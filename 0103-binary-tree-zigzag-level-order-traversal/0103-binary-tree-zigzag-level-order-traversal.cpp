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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        int num = 0;
        while(!q.empty()){
            vector<int>v;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
                v.push_back(temp->val);
            }
            num++;
            if(num%2 == 0)
                reverse(v.begin(),v.end());
            res.push_back(v);
        }
        return res;
    }
};