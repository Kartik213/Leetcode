class Solution {
public:
    int partitionString(string s) {
        int idx = 0;
        int count = 0;
        // unordered_map to keep track of characters in current substring
        unordered_map<char, bool> mp;
        while (idx < s.length()) {
            // if current character has already appeared in current substring
            if (mp.find(s[idx]) != mp.end()) {
                count++; // increment count
                mp.clear(); // clear unordered_map to start a new substring
            }
            // mark current character as seen
            mp[s[idx]] = true;
             // move to next character
            idx++;
        }
    // return number of substrings (add 1 because we need to count the last substring as well)
        return count + 1;
    }
};
