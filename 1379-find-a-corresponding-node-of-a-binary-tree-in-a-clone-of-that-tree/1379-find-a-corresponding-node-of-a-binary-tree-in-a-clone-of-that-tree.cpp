/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& ref){
        if(original == NULL)
            return;
        if(original == target)
            ref = cloned;
        
        dfs(original->left,cloned->left,target,ref);
        dfs(original->right,cloned->right,target,ref);
        
        return ;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ref = NULL;
        dfs(original,cloned,target,ref);
        return ref;
    }
};