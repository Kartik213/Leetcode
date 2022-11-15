class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        //Brute Force
        int n = nums.size();
        int sum = 0;
        int half = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        for(int i=0;i<n;i++){
            if(half == sum-nums[i]){
                return i;
            }
            half += nums[i];
            sum -= nums[i];
        }
        
        return -1;
    }
};