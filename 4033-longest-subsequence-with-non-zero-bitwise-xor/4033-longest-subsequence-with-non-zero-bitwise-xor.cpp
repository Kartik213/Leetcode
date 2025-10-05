class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        for (int x : nums) xor_all ^= x;

        if (xor_all != 0) return n;
        if (n == 1) return 0;

        // Check if all are zero
        bool allZero = all_of(nums.begin(), nums.end(), [](int x){ return x == 0; });
        if (allZero) return 0;

        return n - 1;

    }
};