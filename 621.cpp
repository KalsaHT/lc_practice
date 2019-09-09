#include<queue>
#include<iostream> 


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
                map<char, int> m;
        for (int i = 0; i < tasks.size(); ++i) {
            m[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto ite : m){
            pq.push(ite.second);
        }
        int cycle = n + 1, ret = 0;
        while(!pq.empty()){
            vector<int> tmp;
            int time = 0;
            for (int i = 0; i < cycle; ++i) {
                if (!pq.empty()){
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }

            for (auto cnt : tmp){
                int remainCnt = cnt - 1;
                if(remainCnt > 0)pq.push(remainCnt);
            }
            if(pq.empty()) ret += time;//如果是最后一次调度，不在需要idle来填充
            else ret += cycle;
        }
        return ret;
    }
};