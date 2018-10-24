class Solution(object): 
	def nextPermutation(self, nums): 
		""" 
		:type nums: List[int] 
		:rtype: void Do not return anything, modify nums in-place instead. 
		"""
		if len(nums) <= 1: 
			return 
		raisepos = 0 
		for vpos in range(1, len(nums)): 
			if nums[vpos - 1] < nums[vpos]: 
				raisepos = vpos 
		if raisepos == 0: 
			nums.sort() 
		else: 
			minv = nums[raisepos - 1] 
			reppos = raisepos 
			for repind in range(raisepos + 1, len(nums)): 
				if nums[repind] > minv and nums[repind] < nums[reppos]: 
					reppos = repind 
			tmp = nums[reppos] 
			nums[reppos] = minv 
			nums[raisepos - 1] = tmp 
			nums[raisepos:] = sorted(nums[raisepos:])
