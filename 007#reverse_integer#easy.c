#include<stdio.h>
#include<math.h>
int reverse(int x)
{
	int temp, result = 0, inter = 0;
	if(x >= 0)
		while(x > 0)
		{
			temp = x % 10;
			x /= 10;
			inter  = result * 10 + temp;
			if(inter / 10 < result) //test whether the result will overflow
				return 0;
			result = inter;
		}
	else
	{//for the negative integer
		x = 0 - x;
		while(x > 0)
		{
			temp = x % 10;
			x /= 10;
			inter  = result * 10 + temp;
			if(inter / 10 < result)
				return 0;
			result = inter;
		}
		result = 0 - result;
	}		
	return result;
}