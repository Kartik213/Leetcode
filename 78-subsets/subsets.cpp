class Solution {
public:
    void solve(vector<int>nums, vector<vector<int>> &res, vector<int>temp, int n, int idx){
        if(idx == n){
            res.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(nums, res, temp, n, idx+1);
        temp.pop_back();
        solve(nums, res, temp, n, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        vector<int>temp;
        solve(nums, res, temp, n, 0);
        return res;
    }
};