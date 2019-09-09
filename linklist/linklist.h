#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};


ListNode* createListNode(vector<int>& v){
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    for(int i=0; i<v.size(); i++){
        tmp->next = new ListNode(v[i]);
        tmp = tmp->next;
    }
    return head->next;
}

void print_linklist(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
}