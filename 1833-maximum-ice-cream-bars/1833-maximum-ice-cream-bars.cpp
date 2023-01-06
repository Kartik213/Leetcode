class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        int res = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += costs[i];
            if(sum <= coins)
                res++;
            else
                return res;
        }
        return res;
    }
};