/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(),*right=new ListNode();
        ListNode* node1=left,*node2=right;
        while(head){
            if(head->val<x) left=left->next=head;
            else right=right->next=head;
            head=head->next;
        }
        right->next=NULL;
        left->next=node2->next;
        return node1->next;
    }
};