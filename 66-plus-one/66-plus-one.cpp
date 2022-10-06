class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        vector<int>res;
        for(int i=n-1;i>=0;i--){
            int x = digits[i] + carry;
            carry = x/10;
            res.push_back(x%10);
        }
        while(carry != 0){
            res.push_back(carry%10);
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};