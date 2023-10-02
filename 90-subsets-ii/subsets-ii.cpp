class Solution {
public:
    void solve(vector<int>& nums, int n, set<vector<int>> &ans, int idx, vector<int>temp){
        if(idx == n){
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(nums, n, ans, idx+1, temp);
        temp.pop_back();
        solve(nums, n, ans, idx+1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        solve(nums, n, ans, 0, temp);
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};