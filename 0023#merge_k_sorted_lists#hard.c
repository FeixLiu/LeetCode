/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	struct ListNode* head = NULL;
	struct ListNode** tail = &head;
	int flag = 1;
	int v;
	int i, j;
    
	struct ListNode* tmp[2] = {NULL, NULL};
    
	if(0 == listsSize)
	{
		return NULL;
	}
	if(1 == listsSize)
	{
		return lists[0];
	}
	if(listsSize > 2)
	{
		tmp[0] = mergeKLists(lists, listsSize / 2);
		tmp[1] = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
		return mergeKLists(tmp, 2);
    }
    
	while(flag)
	{
		v = 0x7fffffff;
		flag = 0;
		for(i = 0; i < listsSize; i ++)
		{
			if(!lists[i])
				continue;
			else
			{
				flag = 1;
				if(v >= (lists[i] -> val))
				{
					v = lists[i] -> val;
					j = i;
				}
			}            
		}
		if(flag)
		{
			*tail = lists[j];
			lists[j] = lists[j] -> next;
			tail = &((*tail) -> next);
		}
	}
	return head;
}