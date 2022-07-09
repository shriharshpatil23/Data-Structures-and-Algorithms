// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  Node * createMapping(Node * root, int target, map<Node * ,Node *> &m){
      if(root==NULL)    return root;
      
      Node * ans = NULL;
      queue<Node *> q;
      q.push(root);
      m[root]=NULL;
      while(!q.empty()){
          Node * front = q.front();
          q.pop();
          if(front->data == target){
              ans = front;
          }
          
          if(front->left){
              m[front->left]=front;
              q.push(front->left);
          }
          
          if(front->right){
              m[front->right]=front;
              q.push(front->right);
          }
      }
      return ans;
  }
  
  int burn(Node * root, map<Node * , Node *> &m){
      map<Node* , bool> vis;
      queue<Node*> q;
      int time = 0;
      q.push(root);
      vis[root]=true;
      while(!q.empty()){
          int k = q.size();
          bool flag = false;
          while(k--){
              Node * front = q.front();
              q.pop();
              
              if(front->left && vis[front->left]==false){
                  q.push(front->left);
                  vis[front->left]=true;
                  flag = true;
              }
              if(front->right && vis[front->right]==false){
                  q.push(front->right);
                  vis[front->right]=true;
                  flag = true;
              }
              if(m[front] && vis[m[front]]==false){
                  q.push(m[front]);
                  vis[m[front]]=true;
                  flag = true;
              }
          }
          if(flag)  time++;
      }
      return time;
  }
  
  
    int minTime(Node* root, int t) 
    {
       map<Node * , Node *> m;
       Node * target = createMapping(root,t,m);
       return burn(target,m);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends