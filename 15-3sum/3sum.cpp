class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> res;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=j+1;k<n;k++){
    //                 if(nums[i]+nums[j]+nums[k] == 0){
    //                     vector<int>temp = {nums[i], nums[j], nums[k]};
    //                     sort(temp.begin(), temp.end());
    //                     res.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>>ans;
    //     for(auto it:res){
    //         ans.push_back(it);
    //     }
    //     return ans;
    // }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> res;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         set<int> tempS;
    //         for(int j=i+1;j<n;j++){
    //             int third = -(nums[i] + nums[j]);
    //             if(tempS.find(third) != tempS.end()){
    //                 vector<int> temp = {nums[i], nums[j], third};
    //                 sort(temp.begin(), temp.end());
    //                 res.insert(temp);
    //             }
    //             tempS.insert(nums[j]);
    //         }
    //     }
    //     vector<vector<int>>ans;
    //     for(auto it:res){
    //         ans.push_back(it);
    //     }
    //     return ans;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]){
                         j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};