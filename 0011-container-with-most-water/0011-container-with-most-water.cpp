class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int end = height.size() - 1;
        int start = 0;
        while(end >= start){
            if(height[start] > height[end]){
                int newArea = (end - start)*height[end];
                res = max(res, newArea);
                end--;
            }
            else {
                int newArea = (end - start)*height[start];
                res = max(res, newArea);
                start++;
            }
        }
        return res;
    }
};