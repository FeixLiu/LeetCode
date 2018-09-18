int lengthOfLongestSubstring(char* s) {
	int pos[128];
	int temp;
	for(temp = 0; temp < 128; temp ++) pos[temp] = -1;
    int len = strlen(s);
    if(len == 0)
    	return 0;
    int i, j, maxlen = 1, curlen = 1;
    for(i = 0; i < len; i ++)
    {
    	pos[s[i]] = i;
    	for(j = i + 1; j < len; j ++)
    	{
    		if(pos[s[j]] != -1)
    		{
    			temp = i;
    			i = pos[s[j]];
    			for(; temp <= j; temp ++) pos[s[temp]] = -1;
    			maxlen = (curlen > maxlen) ? curlen : maxlen;
    			curlen = 1;
    			break;
    		}
    		else
    		{
    			pos[s[j]] = j;
    			curlen ++;
    		}
    	}
    	if(j == len)
    	{
    		maxlen = (curlen > maxlen) ? curlen : maxlen;
    		break;
    	}
    }
    return maxlen;
}
