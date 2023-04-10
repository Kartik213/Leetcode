class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> temp1(m);
        // for (int i=0;i<m;i++){
        //     temp1[i] = nums1[i];
        // }
        // int i=0,j=0;
        // int k=0;
        // while(i<m && j<n){
        //     if(temp1[i] < nums2[j]){
        //         nums1[k] = temp1[i];
        //         i++;
        //     }
        //     else{
        //         nums1[k] = nums2[j];
        //         j++;
        //     }
        //     k++;
        // }
        // while(i<m){
        //     nums1[k] = temp1[i];
        //     k++;
        //     i++;
        // }
        // while(j<n){
        //     nums1[k] = nums2[j];
        //     k++;
        //     j++;
        // }
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};