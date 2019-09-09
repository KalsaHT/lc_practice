class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs == []:
            return ""
        common = ""

        min_strs = min(strs)

        for i in range(len(min_strs)):
            s = min_strs[i]
            for c in strs:
                if s != c[i]:
                    return common
            common += s
        
        return common

s = Solution()
strs = ["1234", "123", "1"]
print s.longestCommonPrefix(strs)