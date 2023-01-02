class Solution {
public:
    bool check(char a){
        if('A'<=a && a<='Z')
            return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        int count = 0;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(check(word[i]))
                count++;
        }
        if(count == 1 && check(word[0]))
            return true;
        else if(count == 0 || count == n)
            return true;
        else
            return false;
    }
};