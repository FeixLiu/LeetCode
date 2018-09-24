bool matchstar(char*, char, char*);

bool isMatch(char* s, char* p)
{
	if(p[0] == '\0' && s[0] == '\0') 
		return true;
	if(p[1] == '*')
		return matchstar(s, p[0], p + 2);
	if(*s != '\0' && (p[0] == '.' || p[0] == *s))
		return isMatch(s + 1, p + 1); //cannot use s ++ or p ++ here
	return false;
}

bool matchstar(char* s, char c, char* p)
{ //test for the closure
	do
	{
		if(isMatch(s, p))
			return true;
	} while(*s != '\0' && (*s ++ == c || c == '.'));
	return false;
}

//dynamic programming method
bool isMatch(char* s, char* p) 
{
	if (!s || !p)
		return 0; 
	int len1 = strlen(s), len2 = strlen(p), i, j;
	char **dp = malloc(sizeof(char *) * (len1 + 1));
	for (i = 0; i <= len1; i++)
	{
		dp[i] = calloc(len2 + 1, sizeof(char));
	}
	dp[0][0] = 1;
	i = 0;
	while (i < len2)
	{
		if (p[i] == '*' || i + 1 < len2 && p[i + 1] == '*')
			dp[0][i + 1] = 1;
		else
			break;
		i++;
	}
	i = 0;
	while (i < len1)
	{
		j = 0;
		while (j < len2)
		{
			if (s[i] == p[j] || p[j] == '.')
			{
				if (j + 1 < len2 && p[j + 1] == '*')
					dp[i + 1][j + 1] = dp[i][j] | dp[i + 1][j] | dp[i][j + 1];
				else
					dp[i + 1][j + 1] = dp[i][j];
			}
			else if (j + 1 < len2 && p[j + 1] == '*' || p[j] == '*')
				dp[i + 1][j + 1] = dp[i + 1][j];
			j++;
		}
		i++;
	}
	return dp[len1][len2];
}
