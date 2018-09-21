#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* convert(char* s, int numRows);

int main(void)
{
	char *s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
	printf("%s\n", convert(s, 2));
	return 0;
}

char* convert(char* s, int numRows) 
{
    int lens = strlen(s), groupChara = numRows * 2 - 2, groupLine = numRows - 1;
    if(lens == 0)
    	return "";
    if(numRows == 1)
    {
    	groupChara = 1;
    	groupLine = 1;
    }
    int groupNum = lens / groupChara + 1;
    if(numRows == 1)
        groupNum = lens;
    int i = 0, m = 0, n = 0, down = 0;
    char inter[numRows][groupLine * groupNum];
    for(i = 0; i < numRows; i ++)
    	for(m = 0; m < groupLine * groupNum; m++)
    		inter[i][m] = '\0';
    i = 0, m = 0;
    while(i < lens)
    {
    	inter[m][n] = s[i ++];
    	if(down == 0)
    		if(m == numRows - 1)
    		{
    			down = 1, n ++, m --;
    			if(numRows == 1)
    				m = 0, down = 0;
    		}
    		else
    			m ++;
    	else
    		if(m == 0)
    			down = 0, m ++;
    		else
    			n ++, m --;
    }
    char *result = (char*)malloc((lens + 2) * sizeof(char));
    for(i = 0, n = 0; i < numRows; i ++)
    	for(m = 0; m < groupLine * groupNum; m++)
    	{
    		if(inter[i][m] != '\0')
    			result[n ++] = inter[i][m];
    	}
    result[n] = '\0';
    return result;
}