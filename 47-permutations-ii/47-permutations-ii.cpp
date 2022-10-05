class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int> nums,int indx){
        if(indx == nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int i=indx;i<nums.size();i++){
            if(s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[i],nums[indx]);
            solve(res,nums,indx+1);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        solve(res,nums,0);
        return res;
    }
};