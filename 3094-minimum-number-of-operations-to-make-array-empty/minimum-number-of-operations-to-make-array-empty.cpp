class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int res = 0;
        for(auto x:mp){
            int t = x.second;
            if(t == 1){
                return -1;
            }
            res += t/3;
            if(t%3 != 0){
                res++;
            }
        }
        return res;
    }
};