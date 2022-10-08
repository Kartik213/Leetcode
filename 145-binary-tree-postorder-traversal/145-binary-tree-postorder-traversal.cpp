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
    // void postorder(TreeNode* root, vector<int>& res){
    //     if(root == NULL)
    //         return ;
    //     postorder(root->left,res);
    //     postorder(root->right,res);
    //     res.push_back(root->val);
    // }
    void postorder(TreeNode* root, vector<int>& res){
        TreeNode* current = root;
        stack<TreeNode*>st;
        while(current != NULL || !st.empty()){
            if(current != NULL){
                st.push(current);
                current = current -> left;
            }
            else{
                TreeNode* temp = st.top();
                temp = temp->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        res.push_back(temp->val);
                    }
                }
                else{
                    current = temp;
                }
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        postorder(root, res);
        return res;
    }
};