class Solution {
public:
    bool checkPalindrome(string s, int startIndex, int lastIndex){
        while(startIndex <= lastIndex){
            if(s[startIndex] != s[lastIndex])
                return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void palindromePartition(string s, vector<vector<string>>& res, vector<string>& temp, int n, int idx){
        if(idx == n){
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < n; i++){
            if(checkPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                palindromePartition(s, res, temp, n, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n = s.length();
        palindromePartition(s, res, temp, n, 0);
        return res;
    }
};
