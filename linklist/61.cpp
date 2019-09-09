#include<iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int length=1;
        ListNode* tail=head;
        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }
        //circle
        tail->next = head;
        if(k%=length){
            for(int i=0; i<length-k; i++){
                tail = tail->next;
            }
        }
        ListNode* newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};