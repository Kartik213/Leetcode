class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookies = s.size();
        if(cookies == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i=s.size()-1,j=g.size()-1;
        while(i >= 0 && j >= 0){
            if(s[i] >= g[j]){
                ans++;
                i--;
                j--;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};