class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int freq = 1;
        char prev = s[0];
        res += prev;
        for(int i=1; i<s.length(); i++){
            if(s[i] == prev){
                freq++;
            }else{
                prev = s[i];
                freq = 1;
            }

            if(freq < 3) res += s[i];
        }
        return res;
    }
};