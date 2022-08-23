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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)  return true;
        
        ListNode * mid = head;
        ListNode * fast= head;
        while(fast && fast->next){
            mid = mid->next;
            fast=fast->next->next;
        }
        ListNode * prev = NULL , *curr = mid , *tmp ;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=tmp;
        }
        ListNode * check = head;
        while(prev){
            if(prev->val != check->val) return false;
            
            prev=prev->next;
            check=check->next;
        }
        return true;
        }
};