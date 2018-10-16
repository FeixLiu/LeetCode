# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	def reverseKGroup(self, head, k):
		"""
		:type head: ListNode
		:type k: int
		:rtype: ListNode
		"""
		start = preNode = ListNode(0)
		start.next = l = r = head
		temp = head
		flag = True
		for _ in range(k):
			if r:
				r = r.next
			else:
				return start.next
		while True:
			if not flag:
				return start.next
			cur, nextNode = l, r
			for i in range(k):
				if r:
					r = r.next
				else:
					flag = False
				cur.next, cur, nextNode = nextNode, cur.next, cur
			l, preNode.next, preNode = l.next, nextNode, l
			