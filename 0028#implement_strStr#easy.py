class Solution:
	def strStr(self, haystack, needle):
		"""
		:type haystack: str
		:type needle: str
		:rtype: int
		"""
		if not needle:
			return 0
		if needle not in haystack:
			return -1
		for i in range(len(haystack)):
			if needle == haystack[i:i + len(needle)]:
				return i