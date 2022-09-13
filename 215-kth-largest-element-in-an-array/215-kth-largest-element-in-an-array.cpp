class Solution {
public:
    void heapify(vector<int>& nums,int i){
        int largest = i;
        int left = 2*i +1;
        int right = 2*i + 2;
        if(left<nums.size() && nums[left]>nums[largest]){
            largest = left;
        }
        if(right<nums.size() && nums[right]>nums[largest]){
            largest = right;
        }
        if(largest != i){
            swap(nums[i],nums[largest]);
            heapify(nums,largest);
        }
    }
    void deletion(vector<int>& nums){
        if(nums.size() == 0)
            return ;
        nums[0] = nums[nums.size()-1];
        nums.pop_back();
        heapify(nums,0);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(nums,i);
        }
        for(int i=k-1;i>0;i--){
            deletion(nums);
        }
        return nums[0];
    }
};