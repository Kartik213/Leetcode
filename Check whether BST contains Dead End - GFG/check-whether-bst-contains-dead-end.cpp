//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void allNodes(Node* root, map<int, int> &mp){
    if(!root){
        return ;
    }
    allNodes(root->left, mp);
    mp[root->data] = 1;
    allNodes(root->right, mp);
}

bool solve(Node* root, map<int, int>mp){
    if(!root){
        return false;
    }
    if(!root->left && !root->right){
        int x = root->data - 1;
        int y = root->data + 1;
        if(mp.find(x) != mp.end() && mp.find(y) != mp.end()){
            return true;
        }
    }
    return solve(root->left, mp) || solve(root->right, mp);
}

bool isDeadEnd(Node *root){
    map<int, int> mp;
    mp[0] = 1;
    allNodes(root, mp);
    return solve(root, mp);
}