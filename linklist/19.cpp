#include<iostream>
#include<vector>
#include "linklist.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            length++;
            tmp = tmp->next;
        }
        
        if(n > length) return head;
        if(n == length) return head->next;

        ListNode* del = head;
        while(length-- > n+1) del = del->next;
    
        ListNode* post = del->next->next;
        del->next = post;
        return head;
    }
};

int main(){
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    ListNode* head = createListNode(v);
    Solution s;
    // print_linklist(head);
    ListNode* head2 = s.removeNthFromEnd(head, 4);
    print_linklist(head2);
    return -1;
}