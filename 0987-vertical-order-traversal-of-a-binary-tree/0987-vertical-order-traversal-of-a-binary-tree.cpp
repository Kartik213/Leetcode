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
    map<int, map<int, vector<int>>> nodes;
    void solve(TreeNode* root){
        if(!root){
            return ;
        }
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push(make_pair(root, make_pair(0, 0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* tempNode = temp.first;
            int horizontal = temp.second.first;
            int lvl = temp.second.second;
            nodes[horizontal][lvl].push_back(tempNode->val);
            if(tempNode->left){
                q.push(make_pair(tempNode->left, make_pair(horizontal-1, lvl+1)));
            }
            if(tempNode->right){
                q.push(make_pair(tempNode->right, make_pair(horizontal+1, lvl+1)));
            }
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root);
        for(auto i:nodes){
            vector<int>temp;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};