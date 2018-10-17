class Solution:
	def _findSubStr(self, start, lenstr, lenword, lensubstr, s, counters, ans):
		curr = {}
		wordstart = start
		while start + lensubstr <= lenstr:
			w = s[wordstart : wordstart + lenword]
			wordstart += lenword
			if w not in counters:
				start = wordstart
				curr.clear()
			else:
				curr[w] = curr[w] + 1 if w in curr else 1
				while curr[w] > counters[w]:
					curr[s[start : start + lenword]] -= 1
					start += lenword
				if wordstart - start == lensubstr:
					ans.append(start)
                    
	def findSubstring(self, s, words):
		"""
		:type s: str
		:type words: List[str]
		:rtype: List[int]
		"""
		if not s or not words or not words[0]:
			return []
		counters = {}
		for w in words:
			counters[w] = counters[w] + 1 if w in counters else 1
		ans = []
		lenstr = len(s)
		lenword = len(words[0])
		lensubstr = len(words) * lenword
		for i in range(min(lenword, lenstr - lensubstr + 1)):
			self._findSubStr(i, lenstr, lenword, lensubstr, s, counters, ans)
		return ans