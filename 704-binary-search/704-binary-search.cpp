class Solution {
public:
    // int binarySearch(vector<int>& nums, int target, int low, int high){
    //     if(high >= low){
    //         int mid = low + (high - low)/2;
    //         if(nums[mid] == target)
    //             return mid;
    //         else if(nums[mid]>target)//target lies on the right side
    //             return binarySearch(nums,target,low,mid-1);
    //         else//target lies on the left
    //             return binarySearch(nums,target,mid+1,high);
    //     }
    //     return -1;
    // }
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)//target lies on the right side
                high = mid-1;
            else//target lies on the left
                low = mid+1;
        }
        return -1;
        // return binarySearch(nums,target,low,high);
    }
};