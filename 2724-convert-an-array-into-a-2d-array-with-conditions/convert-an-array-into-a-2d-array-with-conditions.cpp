class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int>mp;
        int maxFreq = 0;
        for (int it:nums ){
            mp[it]++;
            maxFreq = max(maxFreq, mp[it]);
        }
        vector<vector<int>>ans(maxFreq);
        vector<set<int>>check(maxFreq);

        for(int it: nums){
            for(int i=0;i<maxFreq; i++){
                if(check[i].find(it) == check[i].end()){
                    ans[i].push_back(it);
                    check[i].insert(it);
                    break;
                }
            }
        }
        return ans;
    }
};