// Brute Force

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         long long res = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k=j+1; k<n; k++){
//                     long long temp = (long long)(nums[i]-nums[j])*nums[k];
//                     res = max(res, temp);
//                 }
//             }
//         }
//         return res;
//     }
// };

// optimized approach
// if we select nums[j] then nums[i] must be the maximum value from left and nums[k] must be the maximum value from the right side.

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_max(n);
        int max_val = nums[n-1]; 
        for(int i=n-2; i>=0 ;i--){
            right_max[i] = max_val;
            max_val = max(max_val, nums[i]);
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