class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        // O(2n) space complexity
        // vector<int>ans(2*n);
        // for(int i=0;i<n;i++){
        //     ans[i] = nums[i];
        //     ans[i+n] = nums[i];
        // }
        // return ans;
        
        //Reduced space complexity
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};