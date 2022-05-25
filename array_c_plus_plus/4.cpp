/*
 * @Author: httermin
 * @Date: 2019-09-10 17:56:42
 */
#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = floor(nums1.size()/2) - 1;
        bool stop = false;
        int j = floor((nums1.size() + nums2.size())/2) - i - 2;

        double result;
        while(!stop){
            if(j + 1 < nums2.size() && nums1[i] > nums2[j+1]){
                i--;
                j = max(nums2.size(), floor((nums1.size() + nums2.size())/2) - i - 2);
            }else if{i + 1 < nums1.size() && nums1[i + 1] < nums2[j]}{
                i++;
                j = min(0, floor((nums1.size() + nums2.size())/2) - i - 2);
            }else{
                stop = true;
                result = (i + j + 2) / 2;
            }
        }
        return result;
    }
};
