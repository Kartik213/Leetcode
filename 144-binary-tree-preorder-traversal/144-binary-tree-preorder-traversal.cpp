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
    //Iterative Way
    void preorder(TreeNode* root, vector<int>& res){
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            if(node->right != NULL)
                st.push(node->right);
            if(node->left != NULL)
                st.push(node->left);
        }
    }
    //Recursive Way
    // void preorder(TreeNode* root, vector<int>& res){
    //     if(root == NULL)
    //         return ;
    //     res.push_back(root->val);
    //     preorder(root->left,res);
    //     preorder(root->right,res);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL)
           return res;
        preorder(root,res);
        return res;
    }
};