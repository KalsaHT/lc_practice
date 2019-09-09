#include "linklist.h"
#include<iostream>

using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* node = &result;
        int ass=0;
        while(l1||l2||ass){
            int val1 = 0, val2 = 0;
            if(l1 != NULL) val1 = l1->val;
            if(l2 != NULL) val2 = l2->val;
            int tmp = val1 + val2 + ass;
            ass = tmp/10;
            node->next = new ListNode(tmp%10);
            node = node->next;
            l1 = l1? l1->next:l1;
            l2 = l2? l2->next:l2;
        }

        return result.next;
    }
};

int main(){
    ListNode head(5);
    ListNode one(6);
    ListNode two(1);
    ListNode three(2);
    head.next = &one;
    two.next = &three;

    Solution s;
    ListNode* result = s.addTwoNumbers(&head, &two);
    while(result!=NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}