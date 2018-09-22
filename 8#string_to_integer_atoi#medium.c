int myAtoi(char* str)
{
	int lens = strlen(str);
	int i, inter = 0, result = 0;
	for(i = 0; i < lens	 && str[i] == ' '; i ++);
	if(i == lens)
		return 0;
	if(str[i] < '0' || str[i] > '9')
		if(str[i] != '-' && str[i] != '+')
			return 0;
	if(str[i] != '-') //positive integer
	{
		if(str[i] == '+')
			i ++;
		while(i < lens && str[i] >= '0' && str[i] <= '9')
		{
			inter = result * 10 + str[i] - '0';
			if(inter / 10 < result) //the result is overflow
				return pow(2, 31) - 1;
			result = inter;
			i++;
		}
	}
	else
	{
		i ++;
		while(i < lens && str[i] >= '0' && str[i] <= '9')
		{
			inter = result * 10 + str[i] - '0';
			if(inter / 10 < result)
				return 0 - pow(2, 31);
			result = inter;
			i++;
		}
		result = 0 - result;
	}
	return result;
}
