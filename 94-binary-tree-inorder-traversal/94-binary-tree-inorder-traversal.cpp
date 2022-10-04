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
    void inorder(TreeNode* root, vector<int>& res){
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(!st.empty() || node != NULL){
            while(node != NULL){
                st.push(node);
                node = node->left;
            }
            node = st.top();
            res.push_back(node->val);
            st.pop();
            node = node->right;
        }
    }
    
    // void inorder(TreeNode* root,vector<int>& res){
    //     if(root == NULL)
    //         return ;
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        return res;
    }
};