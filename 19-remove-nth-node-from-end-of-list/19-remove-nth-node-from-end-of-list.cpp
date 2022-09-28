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
    int len(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)  return head;
        int x = len(head) - n +1;
        ListNode * curr = head;
        if(x==1){
            head = head->next;
            return head;
        }
        while(x>2){
            curr= curr->next;
            x--;
        }
        curr->next = curr->next->next;
        return head;
    }
};