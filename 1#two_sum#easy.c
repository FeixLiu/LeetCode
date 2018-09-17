int* twoSum(int* nums, int numSize, int target)
{
    int a,b;
    int* result = (int*)malloc(2 * sizeof(int));
    for(a = 0; a < numSize; a++)
    {
        for(b = a + 1; b < numSize; b++)
        {
            if(*(nums+a) + *(nums+b) == target)
            {
                result[0] = a;
                result[1] = b;
                break;
            }
        }
    }
    return result;
}
