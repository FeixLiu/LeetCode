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
