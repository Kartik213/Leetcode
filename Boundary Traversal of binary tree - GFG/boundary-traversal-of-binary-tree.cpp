//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* node){
  if(node->left == NULL && node->right==NULL){
    return true;
  }
  return false;
}
 
void addLeftBound(Node * root, vector<int>& ans){
  //Go left left and no left then right but again check from left
  root = root->left;
  while(root!=NULL){
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left !=NULL) root = root->left;
    else root = root->right;
  }
}
 
void addRightBound(Node * root, vector<int>& ans){
  //Go right right and no right then left but again check from right
  root = root->right;
  //As we need the reverse of this for Anticlockwise
  stack<int> stk;
  while(root!=NULL){
    if(!isLeaf(root)) stk.push(root->data);
    if(root->right !=NULL) root = root->right;
    else root = root->left;
  }
  while(!stk.empty()){
    ans.push_back(stk.top());
    stk.pop();
  }
}
 
//its kind of inorder
void addLeaves(Node * root, vector<int>& ans){
  if(root==NULL){
    return;
  }
  if(isLeaf(root)){
    ans.push_back(root->data); //just store leaf nodes
    return;
  }
  addLeaves(root->left,ans);
  addLeaves(root->right,ans);
}
 
vector <int> boundary(Node *root)
{
  //Your code here
  vector<int> ans;
  if(root==NULL) return ans;
  if(!isLeaf(root)) ans.push_back(root->data); // if leaf then its done by addLeaf
  addLeftBound(root,ans);
  addLeaves(root,ans);
  addRightBound(root,ans);
 
  return ans;
 
}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends