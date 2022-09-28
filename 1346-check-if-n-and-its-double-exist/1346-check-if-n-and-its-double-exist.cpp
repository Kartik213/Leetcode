class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n-1; i++){
            int l = i+1, r = n-1;
            while(l <= r){
                int m = l + (r-l)/2;
                if(arr[i] >= 0){
                    if(arr[i]*2 == arr[m])
                        return true;
                    else if(arr[i]*2 < arr[m])
                        r = m-1;
                    else
                        l = m+1;
                }
                else{
                    if(arr[i] == arr[m]*2)
                        return true;
                    else if(arr[i] < arr[m]*2)
                        r = m-1;
                    else
                        l = m+1;
                }
            }
        }
        return false;
    }
};