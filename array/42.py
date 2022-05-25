#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2021-10-09 14:10:04
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:

    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0

        container = 0
        
        left = 0

        while left < len(height) - 1:
            print("left:", left)
            if left+1 < len(height) and height[left + 1] >= height[left]:
                left += 1
                continue
            _max_point = left+1
            new_left = left
            for right in range(left+1, len(height)):
                _max_point = _max_point if height[_max_point] > height[right] else right
                if height[right] >= height[left]:
                    print("first", left, right)
                    for h in range(left, right):
                        
                        container += height[left] - height[h]

                    new_left = right
                    break
            
            if new_left != left:
                left = new_left
                continue

            _low_height = height[_max_point] if height[_max_point] < height[left] else height[left]
            
            tmp = 0
            for h in range(left+1, _max_point):
                tmp += _low_height - height[h]

            if tmp > 0:
                print("second", left, _max_point)
                container += tmp    
                left = _max_point
                continue

            left += 1

        return container


if __name__ == "__main__":
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    # height = [4,2,0,3,2,5]
    # height = [6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3]
    # height = [4, 2, 3]
    height = [9,6,8,8,5,6,3]
    module = Solution()
    res = module.trap(height)
    print(res)