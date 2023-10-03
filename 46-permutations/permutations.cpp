class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &res, vector<int>temp, int n, vector<int>freq){
        if(temp.size() == n){
            res.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, res, temp, n, freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        vector<int>freq(n, 0);
        solve(nums, res, temp, n, freq);
        return res;
    }
};