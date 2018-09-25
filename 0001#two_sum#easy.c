/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int*, int*, int, int);
int* twoSum(int* nums, int numSize, int target)
{
    int i, pos[numSize];
    for(i = 0; i < numSize; i ++)
        pos[i] = i;
    quickSort(nums, pos, 0, numSize - 1);
    int a = 0, b = numSize - 1;
    int* result = (int*)malloc(2 * sizeof(int));
    while(a < b)
    {
        int sum = nums[a] + nums[b];
        if(sum == target)
        {
            result[0] = pos[a];
            result[1] = pos[b];
            break;
        }
        else if(sum > target) b --;
        else a ++;
    }
    return result;
}

void quickSort(int* nums, int* pos, int left, int right)
{
    if(left < right)
    {
        int temp = pos[left];
        int flag = nums[left];
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && nums[j] >= flag) j --;
            if(i < j) nums[i] = nums[j], pos[i] = pos[j];
            while(i < j && nums[i] <= flag) i ++;
            if(i < j) nums[j] = nums[i], pos[j] = pos[i];
        }
        nums[i] = flag;
        pos[i] = temp;
        quickSort(nums, pos, left, i - 1);
        quickSort(nums, pos, i + 1, right);
    }
}
