# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-02 12:21:38
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        
        if len(height) <= 2:
            return 0

        slow, fast = 0, 2

        while fast < len(height) and height[slow] < height[fast - 1]:
            slow += 1
            fast += 1

        container = 0
        while fast < len(height):
            max_v, max_idx = -1, -1

            while fast < len(height):
                if height[fast] > max_v:
                    max_v = height[fast]
                    max_idx = fast
                    if max_v >= height[slow]:
                        break
                else:
                    fast += 1
            fast = max_idx

            top = max_v if max_v < height[slow] else height[slow]

            for i in range(slow+1, fast):
                container += top - height[i] if top - height[i] > 0 else 0
            
            slow = fast
            fast += 2

            while fast < len(height) and height[slow] < height[fast - 1]:
                slow += 1
                fast += 1

        return container

if __name__ == "__main__":
    solu = Solution()

    examples = [[8,2,8,9,0,1,7,7,9], [9,6,8,8,5,6,3], [4,3,3,9,3,0,9,2,8,3], [4,2,0,3,2,5], [0,1,0,2,1,0,1,3,2,1,2,1], [1, 2, 3, 4, 3, 2, 1]]

    for ex in examples[:]:
        print(solu.trap(ex))