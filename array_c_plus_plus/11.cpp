#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i = 0;
        int j = height.size()-1;
        
        while(i < j){
            max_area = max(max_area, min(height[i], height[j]) * (j- i));

            if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }
        }

        return max_area;
    }
};