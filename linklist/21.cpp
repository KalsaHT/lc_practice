#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* tmp = &head;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                tmp->next = l2;
                l2 = l2->next;
            }else{
                tmp->next = l1;
                l1 = l1->next;
            }
            tmp = tmp->next;
        }
        
        tmp->next = l1?l1:l2;
        return head.next;

    }
};
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
int main(){
    ListNode head(0);
    ListNode one(1);
    ListNode two(0);
    ListNode three(0);
    head.next = &one;
    two.next = &three;

    Solution s;
    ListNode* result = s.mergeTwoLists(&head, &two);
    while(result!=NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}