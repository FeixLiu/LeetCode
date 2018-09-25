void quickSort(int*, int, int);
int threeSumClosest(int* nums, int numsSize, int target)
{
	quickSort(nums, 0, numsSize - 1);
	int i, result = 0, minDiff = INT_MAX;
	for(i = 0; i < numsSize; i ++)
	{
		if(i > 0 && nums[i] == nums[i - 1]) continue;
		int start = i + 1, end = numsSize - 1;
		while(start < end)
		{
			int sum = nums[i] + nums[start] + nums[end];
			int diff = fabs(target - sum);
			if(diff < minDiff)
				minDiff = diff, result = sum;
			int a, b;
			if(nums[start] + nums[end] > target - nums[i]) end --; //when change end and when change start is very crucial
			else if (nums[start] + nums[end] < target - nums[i]) start ++;
			else return target;	
		}
	}
	return result;
}

void quickSort(int* nums, int left, int right)
{
	if(left < right)
	{
		int temp = nums[left];
		int i = left, j = right;
		while(i < j)
		{
			while(i < j && nums[j] >= temp) j --;
			if(i < j) nums[i] = nums[j];
			while(i < j && nums[i] <= temp) i ++;
			if(i < j) nums[j] = nums[i];
		}
		nums[i] = temp;
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);
	}
}
