# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-23 21:30:29
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)

        if m == 0 and n == 0:
            return -1
        elif m == 0:
            if n % 2:
                return nums2[n//2]
            else:
                return (nums2[n//2] + nums2[n//2 - 1]) / 2

        imax, imin = m, 0

        is_odd = (m + n) % 2

        while imin <= imax:
            i = (imax + imin) // 2
            j = ((m + n) // 2) - i 

            if (i < m) and nums1[i] < nums2[j-1]:
                imin += 1
            elif (i > 0) and nums1[i-1] > nums2[j]:
                imax -= 1
            else:
                if i == 0:
                    max_left = nums2[j-1]
                    if j != n:
                        min_right = min(nums1[i], nums2[j])
                    else:
                        min_right = nums1[i]
                elif i == m:
                    min_right = nums2[j]
                    if j != 0:
                        max_left = max(nums1[i-1], nums2[j-1])
                    else:
                        max_left = nums1[i-1]
                
                elif nums1[i] >= nums2[j-1] and nums1[i-1] <= nums2[j]:
                    max_left = max(nums1[i-1], nums2[j-1])
                    min_right = min(nums1[i], nums2[j])
                else:
                    max_left = -1
                    min_right = -1

                if is_odd:
                    return min_right
                else:
                    return (min_right + max_left) / 2
    
                
                
if __name__ == "__main__":
    ss = Solution()

    ex = [([2], [1, 3]), ([7, 8], [9, 10]), ([7, 8], [6, 9, 10]), ([7, 8, 11], [6, 9, 10]),
        ([11, 12], [6, 9, 10, 11]), ([6, 9, 10], [7, 8]), ([0,0], [0,0]), ([], [1,2,3])]


    for num1, num2 in ex:
        print(ss.findMedianSortedArrays(num1, num2))