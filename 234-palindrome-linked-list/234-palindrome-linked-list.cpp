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
    bool pali(string t){
        int s=0;
        int e = t.size()-1;
        while(s<e){
            if(t[s]==t[e]){
                s++;
                e--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        string t = "";
        while(head!=NULL){
            t.push_back(head->val);
            head = head ->next;
        }
        return pali(t);
    }
};