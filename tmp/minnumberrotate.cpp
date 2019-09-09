#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        vector<int> v = sort(rotateArray);
        int result = 0;
        for(int i=0; i<v.size(); i++){
            // cout<<v[i]<<endl;
            result += v[i] * pow(10, i);
        }
        return result;
    }

    vector<int> sort(vector<int> v){
        for(int i=0; i<v.size(); i++){
            for(int j=i; j<v.size(); j++){
                if(v[j] > v[i]){
                    swap(v[i], v[j]);
                }
            }
        }
        return v;
    }
};

int main(){
    int a[] = {3,4,5,1,2};
    vector<int> v(a, a+5);
    Solution ss;
    cout<<ss.minNumberInRotateArray(v);
    return -1;
}