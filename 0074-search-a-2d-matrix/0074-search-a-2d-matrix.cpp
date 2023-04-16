class Solution {
public:
    int upper_bound(vector<int> &v, int target) {
        int left = 0, right = v.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < v[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool binary_search(vector<int> &v, int target) {
        int left = 0, right = v.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == v[mid]) {
                return true;
            } else if (target < v[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> start(m);
        for (int i = 0; i < m; i++) {
            start[i] = matrix[i][0];
        }
        int row = upper_bound(start, target) - 1;
        if (row < 0) { return false; }
        return binary_search(matrix[row], target);
    }
};