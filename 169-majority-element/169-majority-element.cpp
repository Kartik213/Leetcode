class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int x = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2)
                x = nums[i];
        }
        return x;
    }
};