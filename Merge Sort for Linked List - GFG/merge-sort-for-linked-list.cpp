// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node * merge(Node * left , Node * right){
        Node * ans = new Node(-1);
        Node * head1 = left;
        Node * head2 = right;
        Node * head = ans;
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                head->next = head1;
                head = head->next;
                head1=head1->next;
            }else{
                head->next = head2;
                head = head->next;
                head2=head2->next;
            }
        }
        
        if(head1){
            head->next = head1;
        }
        if(head2){
            head->next = head2;
        }
        return ans->next;
    }
    
    Node * findMid(Node * head){
       // if(head==NULL || head->next == NULL)    return head;
        
        Node * slow = head;
        Node * fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
       if(head==NULL || head->next == NULL)    return head;
       
       Node * mid = findMid(head);
       Node * left = head;
       Node * right = mid->next;
       mid->next = NULL;
      
       
       left = mergeSort(left);
       right = mergeSort(right);
       
       Node * ans = merge(left,right);
       
       return ans;
       
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends