class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total_or = 0;
        for(auto it:nums){
            total_or |= it;
        }
        // 2^n
        int total_substes = 1 << (nums.size()-1);
        return total_or*total_substes;
    }
};