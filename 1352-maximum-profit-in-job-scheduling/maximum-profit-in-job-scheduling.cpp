// class Solution {
// public:
//     int n;
//     // find the next task with start time greated or equal to the end time of the previous task
//     int nextIndex(vector<vector<int>>&arr, int l, int target){
//         int r = n-1;
//         int res = n+1;
//         while(l<=r){
//             int mid = l + (r-l)/2;
//             if(arr[mid][0] >= target){
//                 res = mid;
//                 r = mid-1;
//             }else{
//                 l = mid+1;
//             }
//         }
//         return res;
//     }
//     int solve(vector<vector<int>>&arr, int i){
//         if(i >= n){
//             return 0;
//         }
//         int nextIdx = nextIndex(arr, i+1, arr[i][1]);
//         int taken = arr[i][2] + solve(arr, nextIdx);

//         int notTaken = solve(arr, i+1);

//         return max(taken, notTaken);
//     }
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         n = startTime.size();
//         vector<vector<int>>arr(n, vector<int>(3, 0));
//         for(int i=0;i<n;i++){
//             arr[i][0] = startTime[i];
//             arr[i][1] = endTime[i];
//             arr[i][2] = profit[i];
//         }
//         auto comp = [&](auto& vec1, auto& vec2){
//             return vec1[0] <= vec2[0];
//         };
//         sort(begin(arr), end(arr), comp);
//         return solve(arr, 0);
//     }
// };
class Solution {
public:
    int rec( int idx , vector<vector<int>>&jobs , vector<int>&startTime , vector<int>&dp)
    {
        if( idx >= startTime.size())
        {
            return 0;
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        int nextIndex = lower_bound(startTime.begin() , startTime.end() , jobs[idx][1])-startTime.begin();

        int take = jobs[idx][2] + rec( nextIndex , jobs , startTime , dp);

        int notTake = rec( idx + 1 , jobs , startTime , dp);

        return dp[idx] = max( take , notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         
         vector<vector<int>>jobs;
         
         int n = startTime.size();

         vector<int>dp( n , -1);

         for( int i = 0 ; i < startTime.size() ; i++)
         {
             jobs.push_back({ startTime[i] , endTime[i] , profit[i]});
         }

         sort(jobs.begin() , jobs.end());

         sort(startTime.begin() , startTime.end());

         return rec( 0 , jobs , startTime , dp);
    }
};