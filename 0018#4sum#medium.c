/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
	quickSort(nums, 0, numsSize - 1); //must sort the array at first
	int** ans = (int**)malloc(sizeof(int*) * (numsSize * (numsSize - 1) * (numsSize - 2) * (numsSize - 3))/24);
	*returnSize = 0;
	if(numsSize < 4)
		return ans;
	int ansC = 0;
	int i = 0;
	while(i < numsSize - 3)
	{
		if(i > 0 && nums[i] == nums[i - 1]) 
		{// the same with the last calculate
			i ++;
			continue;
		}
		int temp = target - nums[i];
		int j = i + 1;
		while(j < numsSize - 2)
		{
			if(j > i + 1 && nums[j] == nums[j - 1])
			{
				j ++;
				continue;
			}
			int start = j + 1, finish = numsSize - 1;
			while(start < finish)
			{
				int sum = nums[j] + nums[start] + nums[finish];
				if(sum == temp)
				{
					ans[ansC] = (int*)malloc(sizeof(int) * 4);
					ans[ansC][0] = nums[i];
					ans[ansC][1] = nums[j];
					ans[ansC][2] = nums[start];
					ans[ansC][3] = nums[finish];
					ansC ++;
					start ++, finish --;
					while(start < finish && nums[start] == nums[start - 1]) start ++; // the same with the last end
					while(start < finish && nums[finish] == nums[finish + 1]) finish --; // the same with the last first
				}
				else if(sum > temp) finish --; //the end number is too large
				else start ++; // the start number is too samll
			}
			j ++;
		}
		i ++;
	}
	*returnSize = ansC; //the size of the answer array
	return ans;
}

void quickSort(int* nums, int left, int right)
{
	if(left < right)
	{
		int flag = nums[left];
		int i = left, j = right;
		while(i < j)
		{
			while(i < j && nums[j] >= flag) j --;
			if(i < j) nums[i] = nums[j];
			while(i < j && nums[i] <= flag) i ++;
			if(i < j) nums[j] = nums[i];
		}
		nums[i] = flag;
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);
	}
}
