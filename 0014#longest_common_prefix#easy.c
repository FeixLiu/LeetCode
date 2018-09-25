char* longestCommonPrefix(char** strs, int strsSize)
{
	if(strsSize == 0)
		return "";
	char* ans = (char*)malloc(sizeof(char) * 1000);
	int i = 0, j = 0, flag = 1;
	char cur;
	while(1)
	{
		i = 0;
		ans[j] = '\0';
		if(j < strlen(strs[i]))
		{
			cur = strs[i][j];
			i ++;
			while(i < strsSize)
			{
				if(strs[i][j] != cur)
				{
					flag = 0;
					break;
				}
				i ++;
			}
			if(flag == 1)
				ans[j ++] = cur;
			else
				break;
		}
		else
			break;
	}
	return ans;
}
