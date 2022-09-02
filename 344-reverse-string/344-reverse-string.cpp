class Solution {
public:
    void reverse1(vector<char>& s, int i){
        if(i==s.size()/2)
            return;
        char temp = s[i];
        s[i] = s[(s.size()-i)-1];
        s[(s.size()-i)-1] = temp;
        reverse1(s,++i);
    }
    void reverseString(vector<char>& s) {
        reverse1(s,0);
    }
};