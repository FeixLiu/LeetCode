class Solution:
	def removeElement(self, nums, val):
		"""
		:type nums: List[int]
		:type val: int
		:rtype: int
		"""
		count = 0
		for num in nums:
			if num != val:
				nums[count] = num
				count += 1
		return count