#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2021-10-08 16:47:06
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")


class Solution:
    def singleMedian(self, nums):
        if (len(nums) % 2 == 0):
            return (nums[len(nums)//2] + nums[len(nums)//2 - 1]) / 2
        else:
            return nums[len(nums)//2]

    def twiceMedian(self, nums1, nums2, m1, m2):
        if len(nums1) + len(nums2) %2 == 0:
            return nums1[m1] + nums2[m2] / 2
        
        if (len(nums1) - m1 - 1) + (len(nums2) - m2 - 1) > m1 + m2:
            return nums2[m2]
        else:
            return nums1[m1]

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        if len(nums1) == 0:
            return self.singleMedian(nums2)

        if len(nums2) == 0:
            return
            
        n1, n2 = len(nums1), len(nums2)
        a1_start, a1_end = 0, n1-1
        a2_start, a2_end = 0, n2-1
        while 1:
            m1 = a1_start + (a1_end - a1_start) // 2
            m2 = a2_start + (a2_end - a2_start) // 2

            if nums1[m1] < nums2[m2]:
                if m1 == 0:
                    return self.twiceMedian(nums1, nums2, m1, m2)

                elif m1 == n1 - 1:
                    if nums2[0] >= nums1[m1]:
                        return self.singleMedian(nums1+nums2)

                    else:
                        return self.twiceMedian(nums1, nums2, m1, m2)

                elif nums1[m1] >= nums2[m2-1] and (nums1[m1 + 1] >= nums2[m2]):
                    return self.twiceMedian(nums1, nums2, m1, m2)
                
                a1_start = m1
                a2_end = m2
            else:
                if m1 == 0:
                    if nums1[0] >= nums2[n2-1]:
                        return self.singleMedian(nums2 + nums1)
                    else:
                        return self.twiceMedian(nums1, nums2, m1, m2)
                
                elif m1 == n1 - 1:
                    return self.twiceMedian(nums1, nums2, m1, m2)
                
                elif nums1[m1] <= nums2[m2+1] and nums1[m1-1] <= nums2[m2]:
                    return self.twiceMedian(nums1, nums2, m1, m2)
                
                a1_end = m1
                a2_start = m2
             
                        
if __name__ == "__main__":
    s = Solution()

    a1 = [1, 3]
    a2 = [3, 4]

    res = s.findMedianSortedArrays(a1, a2)