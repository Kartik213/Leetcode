class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
        vector<int>ind;
        for(int i=0;i<n;i++){
            int key=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]+key == target){
                    ind.push_back(i);
                    ind.push_back(j);
                }
            }
        }
        return ind;
    }
};