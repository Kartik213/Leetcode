class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(high >= low){
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
                return binarySearch(nums,target,low,mid-1);
            else
                return binarySearch(nums,target,mid+1,high);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(nums[mid] == target)
        //         return mid;
        //     else if(nums[mid]>target)
        //         high = mid-1;
        //     else
        //         low = mid+1;
        // }
        // return -1;
        return binarySearch(nums,target,low,high);
    }
};