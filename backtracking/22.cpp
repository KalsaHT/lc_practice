/*
 * @Author: httermin
 * @Date: 2019-11-01 11:19:12
 */

#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = n, right = n;
        vector<string> result;
        generate(left, right, result, "");
        return result;
    }

    void generate(int left, int right, vector<string> &result, string tmp){
        if(left == 0 && right == 0) result.push_back(tmp);
        if(right < left) return;
        if(right > 0) generate(left, right-1, result, tmp+")");
        if(left > 0) generate(left-1, right, result, tmp+"(");
    }
};


class SolutionBacktracking {
    // backtracking solution
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp_result(2*n, '(');
        
        int row = 1;
        while(row > 0){
            
            if(row < 2*n){
                if(available(tmp_result, "(", row, n)){
                    tmp_result[row] = '(';
                    row++;
                }else if(available(tmp_result, ")", row, n)){
                    tmp_result[row] = ')';
                    row++;
                }else{
                    break;
                }
            }else{
                result.push_back(tmp_result);
                row--;
                while(row > 0){
                    if(tmp_result[row] == '('){
                        if(available(tmp_result, ")", row, n)){
                            tmp_result[row] = ')';
                            row++;
                            break;
                        }else{
                            row--;
                        }
                    }else{
                        row--;
                    }
                }
            }
        }
        return result;
    }

    bool available(string tmp, string bracket, int posi, int num_bracket){
        if(posi == 0) return false;
        int count_left = 0, count_right = 0;
        for(int i=0; i<posi; i++){
            if(tmp[i] == '('){
                count_left++;
            }else if(tmp[i] == ')'){
                count_right++;
            } 
        }

        if(count_left == num_bracket && bracket=="(") return false;
        if(count_right == num_bracket && bracket == ")") return false;
        if(count_left == count_right && bracket == ")") return false;
        
        return true;
    }
};

int main(){

    int n=4;
    Solution ss;

    vector<string> result = ss.generateParenthesis(n);
    for(int i=0; i<result.size(); i++){
        string res = result[i];
        cout<<res<<endl;
    }

    return 1;
}