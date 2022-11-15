class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        //Brute Force
        
//         int n1 = arr1.size();
//         int n2 = arr2.size();
//         int count = 0;
//         int i=0;
        
//         while(i<n1){
//             bool flag = false;
//             int j=0;
//             while(j<n2 && !flag){
//                 if(abs(arr1[i] - arr2[j]) <= d)
//                     flag = true;
//                 j++;
//             }
//             if(!flag)
//                 count++;
//             i++;
//         }
        
//         return count;
        
        //Binary Search
        
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(auto it:arr1){
            if(upper_bound(arr2.begin(),arr2.end(),it+d) == lower_bound(arr2.begin(),arr2.end(),it-d))
                ans++;
        }
        return ans;
    }
};