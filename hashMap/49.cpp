#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        unordered_map<string, int> my_map;
        int count = 0;
        vector<vector<string>> result;
        string element;
        for(int i=0; i<strs.size(); i++){
            element = strs[i];
            sort(element.begin(), element.end());
            if(my_map.find(element) == my_map.end()){
                my_map[element] = count;
                count++;
                vector<string> tmp;
                tmp.push_back(strs[i]);
                result.push_back(tmp);
            }else{
                result[my_map[element]].push_back(strs[i]);
            }
            
        }
        return result;
    }
};

int main(){
    string a[] = {"eat","tea","tan","ate","nat","bat"};
    vector<string> str(a, a+6);
    
    Solution s;
    vector<vector<string>> result=s.groupAnagrams(str);
    // cout<<result.size()<<endl;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    return -1;

}