#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = NULL;

        tmp = reverse(tmp);
        
        while(tmp != NULL){
            if(head->val != tmp->val) return false;
            head = head->next;
            tmp = tmp->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
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


 class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

int main(){
    ListNode head(0);
    ListNode one(1);
    ListNode two(0);
    ListNode three(0);
    head.next = &one;
    one.next = &two;
    two.next = &three;

    Solution s;
    bool result = s.isPalindrome(&one);
    cout<<result<<endl;
    cout<<false<<endl;
    return 0;
}