class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int maxi = -1;
        map<char,int>mp;
        if(s.length() == 0)
            return 0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size() == j-i+1){
                maxi = max(maxi,(j-i+1));
                j++;
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};