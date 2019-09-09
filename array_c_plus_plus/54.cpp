#include<vector>
#include<iostream>

using namespace std; 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        int size_n = matrix.size();
        int size_p = matrix[0].size();
        int length = size_n * size_p;

        int length_r = 0;
        
        int i = 0;
        int j = 0;

        int count = 0;

        result.push_back(matrix[i][j]);
        length_r++;
        // cout<<length<<endl;
        while(length_r != length){
            // 向右走
            while(j + 1 < size_p - count){
                j++;
                result.push_back(matrix[i][j]);
                // cout<<result.size()<<endl;
            }
            //向下走
            // cout<<result.size()<<endl;
            while(i + 1 < size_n - count){
                i++;
                result.push_back(matrix[i][j]);
            }
            // 向左走
            
            length_r = result.size();
            while(j > count && length_r != length){
                j--;
                result.push_back(matrix[i][j]);
            }
            count++;
            // 向上走
            while(i> count && length_r != length){
                i--;
                result.push_back(matrix[i][j]);
            }
            length_r = result.size();
        }
        return result;
    }
};

int main(){
    int a1[] = {1, 2};
    // int a2[] = {4, 5, 6};
    // int a3[] = {7, 8, 9};

    vector<vector<int>> m;
    vector<int> tmp(a1, a1+2);
    m.push_back(tmp);
    // vector<int> tmp2(a2, a2+3);
    // m.push_back(tmp2);
    // vector<int> tmp3(a3, a3+3);
    // m.push_back(tmp3);


    Solution s;
    vector<int> v = s.spiralOrder(m);
    // cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    return -1;
}
