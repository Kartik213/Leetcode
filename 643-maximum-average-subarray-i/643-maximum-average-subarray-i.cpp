class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxSum = INT_MIN;
        int i=0,j=0;
        while(j<nums.size()){
            sum += nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1 == k){
                maxSum = max(maxSum,sum);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return (maxSum/k);
    }
};