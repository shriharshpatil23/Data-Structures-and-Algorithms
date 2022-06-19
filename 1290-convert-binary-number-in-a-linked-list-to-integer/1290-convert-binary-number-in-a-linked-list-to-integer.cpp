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
        ListNode * tmp = NULL;
        ListNode * prev = NULL;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode *a = reverse(head);
        int mul = 1 ;
        int sum = 0;
        while(a){
            sum += (a->val)*mul;
            mul *=2;
            a=a->next;
        }
        return sum;
    }
};