class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // set<int>s;
        // for(int it:nums){
        //     s.insert(it);
        // }
        // int k = s.size();
        // int i=0;
        // for(int it:s){
        //     nums[i] = it;
        //     i++;
        // }
        // return k;
        int i=0;
        int j=1;
        while(j<n){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};