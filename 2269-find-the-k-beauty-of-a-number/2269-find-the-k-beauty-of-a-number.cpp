class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string nums = to_string(num);
        int count = 0;
        int n = nums.length();
        int i=0,j=0;
        string temp = "";
        while(j<n){
            temp += nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1 == k){
                int m = stoi(temp);
                if(m!=0 && num%m == 0 ){
                    count++;
                }
                temp.erase(0,1);
                i++;
                j++;
            }
        }
        return count;
    }
};