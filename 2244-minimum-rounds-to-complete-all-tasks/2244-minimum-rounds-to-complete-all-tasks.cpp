class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int res = 0;
        for (auto it : mp){
            if(it.second==1)
                return -1;
            if(it.second%3==0){
                res += it.second/3;
            }
            else{
                res += it.second/3 + 1;
            }
        }
        return res;
    }
};