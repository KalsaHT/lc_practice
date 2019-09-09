#include<vector>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> tmp(m, 1);
        vector<int> cur(m, 1);
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                cur[j] = cur[j-1] + tmp[j];
            }
            swap(tmp, cur);
        }
        return tmp[m-1];
    }
};