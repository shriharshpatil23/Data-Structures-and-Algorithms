/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> s;
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while(l1 != NULL){
            s.insert(l1);
            l1=l1->next;
        }
        while(l2 != NULL){
            if(s.find(l2)!=s.end()) return l2;
            else l2=l2->next;
        }
        return NULL;
    }
};