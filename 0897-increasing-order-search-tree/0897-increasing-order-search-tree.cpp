/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in){
        if(root == NULL)
            return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        TreeNode* newRoot = new TreeNode(in[0]);
        TreeNode* curr = newRoot;
        
        for(int i=1;i<in.size();i++){
            TreeNode* temp = new TreeNode(in[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        curr->left = NULL;
        curr->right = NULL;
        
        return newRoot;
    }
};