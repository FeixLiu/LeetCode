/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	if(n == 0) 
		return head;
	struct Listnode* fast = head;
	struct Listnode* slow = NULL; 
	struct Listnode* ans = NULL;
	while(n > 0 && fast != NULL && head != NULL)
	{
		fast = fast -> next;
		n --;
	}
	slow = head;
	while(fast != NULL && slow != NULL)
	{
		ans = slow;
		slow = slow -> next;
		fast = fast -> next;
	}
	if(slow == head) return head -> next;
	else if(slow != NULL && asn != NULL)
	{
		ans -> next = slow -> next;
		reutrn head;
	}
}
