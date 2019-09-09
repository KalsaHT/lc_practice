#include<vector>
#include<algorithm>
#include "vector_print.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=0;
                } 
                else if(j!=0 && i==0 && obstacleGrid[i][j-1]==0){
                    obstacleGrid[i][j]=0;
                }else if(j==0 && i!=0 && obstacleGrid[i-1][j]==0){
                    obstacleGrid[i][j] = 0;
                }else{
                    obstacleGrid[i][j] = 1;
                }
            }       
        }

        for(int i=1; i<m; i++){
            for(int j=1;j<n; j++){
                if(obstacleGrid[i][j]!=0 ){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        V2D_print(obstacleGrid);
        return obstacleGrid[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};

int main(){
    int n1[] = {0, 0, 0, 0};
    int n2[] = {0, 1, 0, 0};
    int n3[] = {0, 0, 0, 0};
    int n4[] = {0, 0, 1, 0};
    int n5[] = {0, 0, 0, 0};
    vector<int> m1(n1, n1+4);
    vector<int> m2(n2, n2+4);
    vector<int> m3(n3, n3+4);
    vector<int> m4(n4, n2+4);
    vector<int> m5(n5, n3+4);
    vector<vector<int>> matrix(5, vector<int>(4));
    matrix[0] = m1;
    matrix[1] = m2;
    matrix[2] = m3;
    matrix[3] = m4;
    matrix[4] = m5;
    
    Solution s;
    //vector<vector<int>> result = s.transVector(matrix);
    //V2D_print(result);
    
    int r = s.uniquePathsWithObstacles(matrix);
    cout<<r<<endl;
    return 0;
}