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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)  return head;
        
        int len = 1;
        ListNode *curr=head;
        //calculate Length
        while(curr->next!=NULL){
            len++;
            curr=curr->next;
        }
        //pt last node to head
        curr->next = head;
        k = k%len;
        //get the last node which is to be pointed to NULL
        k = len - k;
        while(k--){
            curr=curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};