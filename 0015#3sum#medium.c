/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int*, int, int);
int** threeSum(int* nums, int numsSize, int* returnSize)
{
	quickSort(nums, 0, numsSize - 1); //must sort the array at first
	int** ans = (int**)malloc(sizeof(int*) * (numsSize * (numsSize - 1) * (numsSize - 2))/6);
	*returnSize = 0;
	if(numsSize < 3)
		return ans;
	int ansC = 0;
	int i = 0;
	while(i < numsSize - 2)
	{
		if(nums[i] > 0) break;
		if(i > 0 && nums[i] == nums[i - 1]) 
		{// the same with the last calculate
			i ++;
			continue;
		}
		int start = i + 1, finish = numsSize - 1;
		while(start < finish)
		{
			int sum = nums[i] + nums[start] + nums[finish];
			if(sum == 0)
			{
				ans[ansC] = (int*)malloc(sizeof(int) * 3);
				ans[ansC][0] = nums[i];
				ans[ansC][1] = nums[start];
				ans[ansC][2] = nums[finish];
				ansC ++;
				start ++, finish --;
				while(start < finish && nums[start] == nums[start - 1]) start ++; // the same with the last end
				while(start < finish && nums[finish] == nums[finish + 1]) finish --; // the same with the last first
			}
			else if(sum > 0) finish --; //the end number is too large
			else start ++; // the start number is too samll
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
