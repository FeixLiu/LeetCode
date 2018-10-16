'''class Solution:
	def removeDuplicates(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		if not nums:
			return None
		if len(nums) == 1:
			return 1
		count = 1
		i = 0
		j = 1
		for j in range(1, len(nums)):
			if nums[j] != nums[i]:
				i = j
				nums[count] = nums[i]
				count += 1
		return count'''
class Solution:
	def removeDuplicates(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		count = 0
		for num in nums:
			if count == 0 or num != nums[count - 1]:
				nums[count] = num
				count += 1
		return count