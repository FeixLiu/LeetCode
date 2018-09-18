/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* former = NULL;
    struct ListNode* head = NULL;
    int carry = 0;
    while(l1 != NULL && l2 != NULL)
    {
    	int temp = l1 -> val + l2 -> val + carry;
    	struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    	new -> next = NULL;
    	new -> val = temp % 10;
    	carry = 0;
    	if(temp >= 10)
    		carry = 1;
    	if(head == NULL)
    		head = new;
    	else
    		former -> next = new;
    	former = new;
    	l1 = l1 -> next;
    	l2 = l2 -> next;
    }
    l1 = l1 ? l1 : l2;
    while(l1 != NULL)
    {
    	int temp = l1 -> val + carry;
    	struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    	new -> next = NULL;
    	new -> val = temp % 10;
    	carry = 0;
    	if(temp >= 10)
    		carry = 1;
    	if(head == NULL)
    		head = new;
    	else
    		former -> next = new;
    	former = new;
    	l1 = l1 -> next;
    }
    if(carry > 0) //this was foggot by me, in which an extra carry digit was needed such as 1 + 99 = 100
    {
    	struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    	new -> next = NULL;
    	new -> val = carry;
    	former -> next = new;
    }
    return head;
}
