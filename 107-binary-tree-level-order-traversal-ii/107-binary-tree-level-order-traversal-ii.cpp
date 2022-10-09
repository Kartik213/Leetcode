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
    // Using stack
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     vector<vector<int>> res;
    //     queue<TreeNode*>q;
    //     if(root == NULL)
    //         return res;
    //     q.push(root);
    //     stack<vector<int>>st;
    //     while(!q.empty()){
    //         vector<int>vec;
    //         int n = q.size();
    //         for(int i=0;i<n;i++){
    //             TreeNode* temp = q.front();
    //             q.pop();
    //             if(temp->left != NULL)
    //                 q.push(temp->left);
    //             if(temp->right != NULL)
    //                 q.push(temp->right);
    //             vec.push_back(temp->val);
    //         }
    //         st.push(vec);
    //     }
    //     while(!st.empty()){
    //         res.push_back(st.top());
    //         st.pop();
    //     }
    //     return res;
    // }
    
    
    //using height concept
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int sum = max(h1,h2)+1;
        return sum;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>>res(h);
        h--;
        if(root == NULL)
            return res;
        queue<TreeNode*>q;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty()){
            vector<int>vec;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
                vec.push_back(temp->val);
            }
            res[h] = vec;
            h--;
        }
        return res;
    }
    // 3rd method -> using normal level order traversal and then reverse the res vector before returning
};