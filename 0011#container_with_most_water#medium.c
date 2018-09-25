int maxArea(int* height, int heightSize)
{
	int max = 0;
	int left = 0, right = heightSize - 1;
	while(left < right)
	{
		int area = (right - left) * (height[left] > height[right] ? height[right --] : height[left ++]);
		max = area > max ? area : max;		
	}
    return max;
}