class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;
        for(auto it:s){
            if(it == '(')
                ans = max(ans,++count);
            if(it == ')')
                count--;
        }
        return ans;
    }
};