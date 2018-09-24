int getArea(int, int, int, int);
int maxArea(int* height, int heightSize)
{
	int max = 0;
	int i, j;
	for(j = 1; j < heightSize; j ++)
		for(i = 0; i < j; i ++)
		{
			int area = getArea(height[i], height[j], i, j);
			if(area > max)
				max = area;
		}
	return max;
}

int getArea(int hi, int hj, int i, int j)
{
	int lenght = j - i;
	int height = hi > hj ? hj : hi;
	return height * lenght;
}
