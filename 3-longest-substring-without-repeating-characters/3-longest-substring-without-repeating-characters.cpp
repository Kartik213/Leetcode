class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int maxi = -1;
        map<char,int>mp;
        if(s.length() == 0)
            return 0;
        while(j<s.length()){
            //mapping the character
            mp[s[j]]++;
            //if map size is equal to the window the window size this means substring has all unique characters
            //and can check for result
            if(mp.size() == j-i+1){
                maxi = max(maxi,(j-i+1));
                j++;
            }
            //if map size is less than window size this means it has some duplicate characters
            //remove the characters while map size is less than the window size
            //this will remove the duplicate elements from the map
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    //if the map value of a character became zero the remove it from the map
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