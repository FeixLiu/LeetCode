class Solution:
	def divide(self, dividend, divisor):
		"""
		:type dividend: int
		:type divisor: int
		:rtype: int
		"""
		a = int(dividend / divisor)
		if a <= 2147483647 and a >= -2147483648:
			return a
		elif a > 2147483647:
			return 2147483647
		elif a < -2147483648:
			return -2147483648
