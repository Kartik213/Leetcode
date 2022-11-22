class Solution {
public:
    string makeGood(string s) {
        for(int i = 0; i < s.length(); ++i){
            int len = s.length();
            if(s[i] == s[i+1] + 32 || s[i] + 32 == s[i+1])
                s.erase(i, 2);
            if(len != s.length())
                i = -1;
        }
        return s;
    }
};