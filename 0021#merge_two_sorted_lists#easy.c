/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = NULL;
	struct ListNode* former = NULL;
	while(l1 != NULL && l2 != NULL)
	{
		struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
		new -> next = NULL;
		if(l1 -> val > l2 -> val)
		{
			new -> val = l2 -> val;
			l2 = l2 -> next;
		}
		else
		{
			new -> val = l1 -> val;
			l1 = l1 -> next;
		}
    	if(head == NULL)
    		head = new;
    	else
    		former -> next = new;
    	former = new;	
	}
	l1 = l1 ? l1 : l2;
	if(l1 != NULL)
    	if(head == NULL)
    		head = l1;
    	else
    		former -> next = l1;
	return head;
}