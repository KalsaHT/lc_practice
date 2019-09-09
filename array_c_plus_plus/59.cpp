#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int> > result(n, vector<int>(n, 0));
        if(n == 0) return result;
        
        int num=1;
        int i=0, j=0;
        int count = 0;
        result[i][j] = num;
        while(num < n*n){
            
            // 向右走
            while(j + 1 < n - count){
                j++;
                num++;
                result[i][j] = num;
            }

            // 向下走
            while(i + 1 < n - count){
                i++;
                num++;
                result[i][j] = num;
            }

            // 向左走
            while(j > count && num <= n*n){
                j--;
                num++;
                result[i][j] = num;
            }
            count++;
            //向上走
            while(i > count && num <= n*n){
                i--;
                num++;
                result[i][j] = num;
            }

        }
        return result;
    }
};