class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int zero = 0, one = 0, two = 0;
        // for(auto it: nums){
        //     if(it == 0)
        //         zero++;
        //     else if(it == 1)
        //         one++;
        //     else
        //         two++;
        // }
        // int i=0;
        // for(i=0;i<zero;i++){
        //     nums[i] = 0;
        // }
        // for(i;i<one+zero;i++){
        //     nums[i] = 1;
        // }
        // for(i;i<two+one+zero;i++){
        //     nums[i] = 2;
        // }
        vector<int> freq(3,0);
        for(auto it: nums){
            freq[it]++;
        }
        int i=0, j=0;
        while(i<3){
            if(freq[i]>0){
                nums[j] = i;
                j++;
                freq[i]--;
            }else{
                i++;
            }
            
        }
    }
};