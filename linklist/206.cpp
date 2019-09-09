#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur!=NULL){
            pre->next = cur->next;
            cur->next = head;
            head = cur;
            cur = pre->next;
        }
        return head;
    }
};


class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* tmp=NULL;
        ListNode* next;
        while(head!=NULL){
            next = head->next;
            head->next = tmp;
            tmp = head;
            head = next;
        }
        return tmp;
    }
};