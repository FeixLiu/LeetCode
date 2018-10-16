'''# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	def swapPairs(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		if not head : 
			return None
		if not head.next:
			return head

		t = head.next.next
		head.next.next = head
		head = head.next
		head.next.next = t
		if not t:
			return head

		p1 = head.next
		p2 = p1.next
		while p2.next:
			p1.next = p2.next
			p2.next = p2.next.next
			p1.next.next = p2
			if not p2.next:
				break
			p1 = p2
			p2 = p2.next

		return head'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	def swapPairs(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		if head == None:
			return None
		if head.next == None:
			return head
		node2 = head.next
		temp = node2.next
		node2.next = head
		head.next = self.swapPairs(temp)
		return node2