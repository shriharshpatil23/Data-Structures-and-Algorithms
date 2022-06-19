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
    
    ListNode * reverse(ListNode * head){
        ListNode * curr = head;
        ListNode * prev = NULL;
        ListNode * tmp = NULL;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    ListNode * middle (ListNode * head){
        ListNode * first = head;
        ListNode * second = head;
        while(second && second->next){
            first = first ->next;
            second = second -> next -> next;
        }
        return first;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode * start = head;
        ListNode * mid = middle(head);
        ListNode * mid2 = reverse(mid);
        while(mid2){
            if(mid2->val != start->val) return false;
            
            mid2 = mid2->next;
            start = start->next;
        }
        return true;
    }
};