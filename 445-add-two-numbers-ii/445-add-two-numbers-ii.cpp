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
    ListNode * reverse(ListNode * root){
        if(root==NULL || root->next == NULL)    return root;
        
        ListNode * curr = root;
        ListNode * prev = NULL;
        ListNode * temp ;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p = reverse(l1);
        ListNode * q = reverse(l2);
        ListNode * ans = new ListNode(0);
        ListNode * curr = ans;
        int carry = 0;
        while(p || q){
            int x=(p!=NULL)?p->val:0;
            int y=(q!=NULL)?q->val:0;
            int sum=carry+x+y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr=curr->next;
            if(p) p = p->next;
            if(q) q = q->next;
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        ListNode * res = reverse(ans->next);
        return res;
    }
};