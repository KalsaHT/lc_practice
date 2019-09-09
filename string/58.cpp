#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if(s == "") return 0;
        std::vector<std::string> result;
        std::stringstream ss(s);
        std::string item;
        while(std::getline(ss, item, ' ')){
            if(item != "") result.push_back(item);
        }
        if(result.empty()) return 0;
        return result.back().size();
    }
};

int main(){
    std::string m = " ";
    Solution s;
    // std::cout<<s.lengthOfLastWord(m);
    std::vector<std::string> v;
    std::cout<<v.back().size();
    return -1;
}