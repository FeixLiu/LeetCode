double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int merge[nums1Size + nums2Size];
    int i = 0, j = 0, count = 0;
    while(i < nums1Size && j < nums2Size)
    {
    	if(nums1[i] < nums2[j])
    	{
    		merge[count] = nums1[i];
    		count ++;
    		i ++;
    	}
    	else
    	{
    		merge[count] = nums2[j];
    		count ++;
    		j ++;
    	}
    }
    while(i < nums1Size)
    {
    	merge[count] = nums1[i];
    	count ++;
    	i ++;
    }
    while(j < nums2Size)
    {
    	merge[count] = nums2[j];
    	count ++;
    	j ++;
    }
    double mid = (nums1Size + nums2Size) / 2.0; 
    //be aware of the 2.0, if you write 2 here, 
    //the result of the mid will be int, for the two numsize are all int
    if(mid == (int)mid)
    	return (merge[(int)mid - 1] + merge[(int)mid]) / 2.0;
    else
    	return merge[(int)(mid)];
}