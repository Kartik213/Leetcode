class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(auto it:nums){
                if(it <= mid){
                    ++count;
                }
            }
            if(count <= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};