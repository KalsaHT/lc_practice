#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class MinStack1 {
private:
    vector<int> stack;
public:
    /** initialize your data structure here. */
    MinStack1() {}
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        int min_element = INT_MAX;
        for(int i=0; i<stack.size(); i++){
            min_element = min(min_element, stack[i]);
        }
        return min_element;
    }
};

class MinStack {
private:
    vector<int> stack1;
    vector<int> stack2;

public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stack1.push_back(x);
        if(stack2.size()==0 || x<=stack2[stack2.size()-1]){
            stack2.push_back(x);
        }
    }
    
    void pop() {
        int num = stack1[stack1.size()-1];
        stack1.pop_back();
        if(num == stack2[stack2.size()-1]) stack2.pop_back();
    }
    
    int top() {
        return stack1[stack1.size()-1];
    }
    
    int getMin() {
        return stack2[stack2.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(){
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<obj.getMin()<<endl;
    obj.pop();
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;

    return -1;
};