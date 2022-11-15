class Solution {
public:
    double trimMean(vector<int>& arr) {
        double n = arr.size();
        double remove = (5*n)/100;
        sort(arr.begin(),arr.end());
        long double sum;
        for(int i=remove;i<n-remove;i++){
            sum += arr[i];
        }
        n -= 2*remove;
        return sum/n;
    }
};