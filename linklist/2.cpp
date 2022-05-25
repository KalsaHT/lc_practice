/*
 * @Author: httermin
 * @Date: 2019-09-09 23:37:52
 */
#include "linklist.h"
#include<math.h>
#include<iostream>

using namespace std;

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* cur = &result;

        bool stop = false;

        int num1, num2, add = 0;

        while(l1!=NULL || l2!=NULL || add!=0){
            if(l1 != NULL) num1 = l1->val;
            if(l2 != NULL) num2 = l2->val;

            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;

            cur->next = new ListNode((add + num1 + num2) % 10);
            add = (add + num1 + num2) / 10;
            num1, num2 = 0;
            cur = cur->next;

        }
        return result.next;

    }


    ListNode* addTwoNumbers_(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode result(0);
        ListNode* cur = &result;
        int tmp;
        while(l1!=NULL||l2!=NULL||add!=0){
            int val1 = 0;
            int val2 = 0;
            if(l1 != NULL) val1 = l1->val;
            if(l2 != NULL) val2 = l2->val;
            tmp = val1 + val2 + add;
            add = tmp / 10;
            cur->next = new ListNode(tmp%10);
            cur = cur->next;
            
            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;
        }
        return result.next;
    }
};


class SolutionOLD {
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