char* longestPalindrome(char* s) 
{
    int lens = strlen(s);
    int i = 0, floor = 0, ceil = 0, maxlen = 1, count = 1, curmax = 1;
    while(i < lens - maxlen)
    {
    	if(s[i] == s[i + 1])
    	{
    		curmax = 2;
    		while((i - count) >= 0 && (i + count + 1) < lens && s[i - count] == s[i + count + 1])
    		{
    			curmax += 2;
    			count ++;
    		}
    		if(curmax > maxlen)
    		{
    			floor = i - count + 1;
    			ceil = i + count;
    			maxlen = curmax;
    		}
    		count = 1;
    		curmax = 1;
    	}
    	while((i - count) >= 0 && (i + count) < lens && s[i - count] == s[i + count])
    	{
    		curmax += 2;
    		count ++;
    	}
    	if(curmax > maxlen)
    	{
    		floor = i - count + 1;
    		ceil = i + count - 1;
    		maxlen = curmax;
    	}
    	count = 1;
    	curmax = 1;
    	i ++;
    }
    char* result = (char*)malloc((ceil -floor + 2) * sizeof(char));
    for(i = 0; i < ceil -floor + 1; i ++)
    	result[i] = s[floor + i];
    result[ceil -floor + 1] = '\0';
    return result;
}
