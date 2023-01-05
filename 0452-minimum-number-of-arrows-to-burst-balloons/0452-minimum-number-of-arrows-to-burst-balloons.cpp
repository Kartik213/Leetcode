class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int last = points[0][1];
        int n = points.size();
        int res = 1;
        for(int i = 0;i<n;i++){
            if(last < points[i][0]){
                res++;
                last = points[i][1];
            }
            last = min(points[i][1],last);
        }
        return res;
    }
};