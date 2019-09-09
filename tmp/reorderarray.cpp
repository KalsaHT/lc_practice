#include<vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> tmp;
        for(int i=0; i<array.size(); i++){
            if(array[i]%2 == 1) tmp.push_back(array[i]);
        }
        for(int j=0; j<array.size(); j++){
            if(array[j]%2 == 0) tmp.push_back(array[j]);
        }
        array = tmp;
    }
};