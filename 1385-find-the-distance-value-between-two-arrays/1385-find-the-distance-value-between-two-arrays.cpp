class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int count = 0;
        int i=0;
        
        while(i<n1){
            bool flag = false;
            int j=0;
            while(j<n2 && !flag){
                if(abs(arr1[i] - arr2[j]) <= d)
                    flag = true;
                j++;
            }
            if(!flag)
                count++;
            i++;
        }
        
        return count;
    }
};