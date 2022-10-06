class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //2 pointer approach
        // int n = nums.size();
        // int j=0;
        // for(int i=1;i<n;i++){
        //     if(nums[j] != nums[i]){
        //         j++;
        //         nums[j] = nums[i];
        //     }
        // }
        // return j+1;
        
        //using set
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto it:s){
            nums[i] = it;
            i++;
        }
        return s.size();
    }
};