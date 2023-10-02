class Solution {
public:
    void solve(vector<int>candidates, vector<vector<int>> &res, vector<int>temp, int target, int n, int idx){
        // if(idx == n){
        //     if(target == 0){
        //         sort(temp.begin(), temp.end());
        //         res.insert(temp);
        //     }
        //     return ;
        // }
        // if(candidates[idx] <= target){
        //     temp.push_back(candidates[idx]);
        //     solve(candidates, res, temp, target-candidates[idx], n, idx+1);
        //     temp.pop_back();
        // }
        // solve(candidates, res, temp, target, n, idx+1);
         if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }
            if (candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates, res, temp, target-candidates[i], n, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int>temp;
        int n = candidates.size();
        solve(candidates, res, temp, target, n, 0);
        return res;
    }
};