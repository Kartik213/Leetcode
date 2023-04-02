class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int left = 0;
            int right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long product = (long long)spells[i] * (long long)potions[mid];
                if (product >= success) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            pairs[i] = m - left;
        //     long long product = (long long)spells[i] * (long long)potions[m-1];
        //     if(product < success){
        //         pairs[i] = 0;
        //     }
        //     else{
        //         int left = 0;
        //         int right = m - 1;
        //         while (left <= right) {
        //             int mid = left + (right - left) / 2;
        //             product = (long long)spells[i] * (long long)potions[mid];
        //             if (product >= success) {
        //                 right = mid - 1;
        //             } else {
        //                 left = mid + 1;
        //             }
        //         }
        //         pairs[i] = m - left;
        //     }
        }
        return pairs;
    }
};
