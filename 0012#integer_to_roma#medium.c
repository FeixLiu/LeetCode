char* intToRoman(int num)
{
	int count = 0;
	char* ans = (char*)malloc(sizeof(char) * 1000);
	ans[0] = '\0';
	while(num >= 1000)
	{
		ans[count] = 'M';
		count ++;
		ans[count] = '\0';
		num -= 1000;
	}
	if(num >= 900)
	{
		ans[count] = 'C';
		count ++;
		ans[count] = 'M';
		count ++;
		ans[count] = '\0';
		num -= 900;
	}
	if(num >= 500)
	{
		ans[count] = 'D';
		count ++;
		ans[count] = '\0';
		num -= 500;
	}
	if(num >= 400)
	{

		ans[count] = 'C';
		count ++;
		ans[count] = 'D';
		count ++;
		ans[count] = '\0';
		num -= 400;
	}
	while(num >= 100)
	{
		ans[count] = 'C';
		count ++;
		ans[count] = '\0';
		num -= 100;
	}
	if(num >= 90)
	{
		ans[count] = 'X';
		count ++;
		ans[count] = 'C';
		count ++;
		ans[count] = '\0';
		num -= 90;
	}
	if(num >= 50)
	{
		ans[count] = 'L';
		count ++;
		ans[count] = '\0';
		num -= 50;
	}
	if(num >= 40)
	{

		ans[count] = 'X';
		count ++;
		ans[count] = 'L';
		count ++;
		ans[count] = '\0';
		num -= 40;
	}
	while(num >= 10)
	{
		ans[count] = 'X';
		count ++;
		ans[count] = '\0';
		num -= 10;
	}
	if(num >= 9)
	{
		ans[count] = 'I';
		count ++;
		ans[count] = 'X';
		count ++;
		ans[count] = '\0';
		num -= 9;
	}
	if(num >= 5)
	{
		ans[count] = 'V';
		count ++;
		ans[count] = '\0';
		num -= 5;
	}
	if(num >= 4)
	{
		ans[count] = 'I';
		count ++;
		ans[count] = 'V';
		count ++;
		ans[count] = '\0';
		num -= 4;
	}
	while(num >= 1)
	{
		ans[count] = 'I';
		count ++;
		ans[count] = '\0';
		num -= 1;
	}	
	return ans;	
}
