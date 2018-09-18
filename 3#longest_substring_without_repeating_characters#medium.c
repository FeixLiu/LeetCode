int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if(len == 0)
    	return 0;
    int i, j, maxlen = 1, curlen = 1;
    for(i = 0; i < len; i ++)
    {
    	for(j = i + 1; j < len; j ++)
    	{
    		int diff = 0, temp;
    		for(temp = i; temp < j; temp++)
    		{
    			if(s[temp] == s[j])
    			{
    				diff = 1;
    				i = temp;
    				break;
    			}
    		}
    		if(diff == 1)
    		{
    			diff = 0;
    			maxlen = (curlen > maxlen) ? curlen : maxlen;
    			curlen = 1;
    			break;
    		}
    		else
    			curlen ++;
    	}
    	if(j == len)
    	{
    		maxlen = (curlen > maxlen) ? curlen : maxlen;
    		break;
    	}
    }
    return maxlen;
}
