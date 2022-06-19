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
class cmp{
    public : 
    bool operator() (ListNode *a, ListNode * b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode *> , cmp> pq;
        for(auto x : lists){
            while(x){
                pq.push(x);
                x=x->next;
            }
        }
        ListNode * ans = new ListNode();
        ListNode * head = ans ;
        
        while(!pq.empty()){
            head->next = new ListNode(pq.top()->val);
            head = head->next;
            pq.pop();
        }
        return ans->next;
    }
};