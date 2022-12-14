class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans = INT_MAX;
        while(j<nums.size()){
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1 == k){
                ans = min(ans,nums[j]-nums[i]);
                i++;
                j++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        else{
            return ans;
        }
    }
};