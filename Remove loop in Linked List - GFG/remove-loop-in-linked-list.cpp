// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
       // unordered_set<Node*> s;
        // Node * slow = head->next;
        // Node * fast = head->next->next;
        // bool isPresent = false;
        // while(slow != NULL || fast != NULL){
        //     if(slow == fast){
        //         isPresent = true;
        //         break;
        //     }
        
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // if(isPresent == false)  return;
        
        // s.insert(head);
        // Node *tmp = head;
        // while(1){
        //     Node * t = tmp ->next;
            
        //     if(s.find(t)!= s.end()){
        //         tmp->next = NULL;
        //         break;
        //     }
        //     tmp = tmp->next;
        //     s.insert(tmp);
        // }
         Node* temp = head;
   
       unordered_set<Node*>s;
       int yo =1;
       Node* sup = head;
       while (temp->next != NULL){
           
           if (s.find(temp) != s.end()){
               sup->next = NULL;
               break;
           }
           s.insert(temp);
           temp = temp->next;
           if (yo !=1){
               sup = sup->next;
           }
           yo++;
       }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends