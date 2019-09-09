#include<vector>
#include<iostream>

using namespace std; 

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        sorted(intervals);
        vector<Interval> result;
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            Interval last(result.back().start, result.back().end);
            if(last.end < intervals[i].start){
                result.push_back(intervals[i]);
            }else if(last.end == intervals[i].start || last.end < intervals[i].end){
                Interval tmp(last.start, intervals[i].end);
                result.back() = tmp;
            }
        }
        return result;
    }

    void sorted(vector<Interval>& intervals){
        int size_i = intervals.size();
        for(int i=0; i<size_i-1; i++){
            int min_posi = i;
            for(int j=i+1; j<size_i; j++){
                if(intervals[j].start < intervals[min_posi].start){
                    min_posi = j;
                }
            }
            swap(intervals[i], intervals[min_posi]);
        }
    }
};

int main(){
    Interval a1(-1, 3);
    Interval a2(2, 6);
    Interval a3(8, 10);
    Interval a4(15, 18);

    vector<Interval> v;
    v.push_back(a1); 
    v.push_back(a4);
    v.push_back(a2);
    v.push_back(a3);

    Solution s;
    vector<Interval> result = s.merge(v);
    for(int i=0; i<result.size(); i++){
        cout<<result[i].start<<" "<<result[i].end<<endl;
    }
    return -1;
}