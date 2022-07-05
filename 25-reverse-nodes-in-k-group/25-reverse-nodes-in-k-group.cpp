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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        if(head==NULL)  return head;
        
        for(int i=0;i<k;i++){
            if(!temp)   return head;
            temp=temp->next;
        }
        
        //reversing a Linked List
        int K = k;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tmp ;
        while(curr && K--){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr  = tmp;
        }
        //hypothesis
        if(curr != NULL){
            head -> next = reverseKGroup(curr,k);
        }
        return prev;
    }
};