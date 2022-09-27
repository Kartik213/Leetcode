class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int Maxsum = threshold*k;
        int count = 0;
        int sum = 0;
        while(j<arr.size()){
            sum += arr[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(sum >= Maxsum){
                    count++;
                }
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};