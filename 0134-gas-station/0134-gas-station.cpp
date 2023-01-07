class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumCost = 0;
        int idx = 0;
        int sumGas = 0;
        int currGas = 0;
        int n = gas.size();

        for(int i=0;i<n;i++){
            sumGas += gas[i];
            sumCost += cost[i];
            currGas += gas[i]-cost[i];
            if(currGas < 0){
                currGas = 0;
                idx = i+1;
            }
        }
        
        if(sumGas < sumCost)
            return -1;
        return idx;
    }
};