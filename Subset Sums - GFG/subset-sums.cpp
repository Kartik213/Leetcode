//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>arr, int n, vector<int> &res, int idx, int sum){
        if(idx == n){
            res.push_back(sum);
            return;
        }
        solve(arr, n, res, idx+1, sum+arr[idx]);
        solve(arr, n, res, idx+1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int>res;
        solve(arr, n, res, 0, 0);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends