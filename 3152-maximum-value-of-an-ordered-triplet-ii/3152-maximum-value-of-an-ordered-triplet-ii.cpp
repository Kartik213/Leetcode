class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>right_max(n);
        int max_num = nums[n-1];
        for(int i=n-2; i>=0; i--){
            right_max[i] = max_num;
            max_num = max(max_num, nums[i]);
        }
        long long res = 0;
        int left_max = nums[0];
        for(int i=1; i<n-1; i++){
            long long temp = (long long)(left_max-nums[i])*right_max[i];
            res = max(res, temp);
            left_max = max(left_max, nums[i]);
        }
        return res;
    }
};