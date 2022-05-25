
from typing import List  


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) < 2:
            return []
            
        diff_dict = {n:i for i, n in enumerate(nums)}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in diff_dict and (diff_dict[diff] != i):
                return sorted([i, diff_dict[target - n]])


        return []