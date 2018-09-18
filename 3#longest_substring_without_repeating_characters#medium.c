/*this solution is the best
  just remember the postition of each character
  and use the position to update curlen
  you do not have to re-calculate it from zero
  but you can use the already knew knowledge of the string
*/
int lengthOfLongestSubstring(char* s) {
	int pos[128];
	int temp;
	for(temp = 0; temp < 128; temp ++) pos[temp] = -1;
    int len = strlen(s);
    if(len == 0)
    	return 0;
    int i, j, maxlen = 1, curlen = 1;
    for(i = 0, j = i + 1; j < len; j ++)
    {
   		pos[s[i]] = i;
    	if(pos[s[j]] != -1)
    	{
    		maxlen = (curlen > maxlen) ? curlen : maxlen;
    		curlen -= pos[s[j]] - i;
    		temp = i;
    		i = pos[s[j]] + 1;
    		for(; temp <= i - 1; temp ++) pos[s[temp]] = -1;
    	}
    	else
    		curlen ++;
    	pos[s[j]] = j;
    }
    if(j == len)
    	maxlen = (curlen > maxlen) ? curlen : maxlen;
    return maxlen;
}
