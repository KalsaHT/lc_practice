/*
 * @Author: httermin
 * @Date: 2019-09-18 22:03:10
 */


#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // cout<<m<<" "<<n<<endl;
        if (m == 1 && n == 1) return 1;
        else if(m == 1) return uniquePaths(1, n-1);
        else if(n == 1) return uniquePaths(m - 1, 1);
        else return uniquePaths(m - 1, n) + uniquePaths(m, n-1);
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> tmp(n, 1);
        vector<vector<int>> matrix(m, tmp);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};

int main(){
    Solution2 ss;
    cout<<ss.uniquePaths(19,13)<<endl;
    return -1;
}