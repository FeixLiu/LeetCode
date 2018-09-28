/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	if(n == 0) return head;
	struct Listnode *fast = head, *slow = NULL, *ans = NULL;
	int temp;
	for(temp = n; temp > 0; fast = fast -> next, n --);
	slow = head;
	while(fast != NULL)
	{
		ans = slow;
		slow = slow -> next;
		fast = fast -> next;
	}
	if(slow == head) return head -> next;
	else
	{
		ans -> next = slow -> next;
		reutrn head;
	}
}
