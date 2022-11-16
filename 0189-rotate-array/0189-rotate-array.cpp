class Solution {
public:
    void reverse(vector<int>&nums, int start, int last){
        int left = start;
        int right = last;
        while(right>left){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        //Intutive Approach
        // int n = nums.size();
        // deque<int>dq;
        // for(int i=0;i<n;i++){
        //     dq.push_back(nums[i]);
        // }
        // for(int i=0;i<k;i++){
        //     int x = dq.back();
        //     dq.pop_back();
        //     dq.push_front(x);
        // }
        // for(int i=0;i<n;i++){
        //     nums[i] = dq.front();
        //     dq.pop_front();
        // }
        
        //reducing for loop
        
        int n = nums.size();
        k %= n;
        if(k<0)
            k += n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
        
        
    }
};