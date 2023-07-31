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
    TreeNode* solve(vector<int> preorder, int max, int min, int& pre, int size, int key){
        if(pre >= size){
            return NULL;
        }
        TreeNode* root = NULL;
        if(key < max && key > min){
            root = new TreeNode(key);
            pre++; 
            if(pre < size){
                root->left = solve(preorder, key, min, pre, size, preorder[pre]);
            }
            if(pre < size){
                root->right = solve(preorder, max, key, pre, size, preorder[pre]);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pre = 0;
        TreeNode* root = solve(preorder, INT_MAX, INT_MIN, pre, preorder.size(), preorder[0]);
        return root;
    }
};