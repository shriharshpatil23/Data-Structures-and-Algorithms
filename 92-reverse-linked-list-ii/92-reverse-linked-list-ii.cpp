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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
          if(left==right) 
            return head;
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        
        ListNode* one_prev=nullptr;
        int cnt = 1;
        while(curr and cnt < left){
            one_prev=curr;
            curr = curr->next;
            cnt++;
        }
        
        
        prev = one_prev;
        while(cnt <= right and curr){
            ListNode* adv = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = adv;
            
            cnt++;
        }
        
        
        // change the links
        if(one_prev==NULL){
            head->next = curr;
            head = prev;
        }else{
           
            if(one_prev->next)
                one_prev->next->next = curr;
            
            one_prev->next = prev;
        }
        
        
        return head;
    }
};