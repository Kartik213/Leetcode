class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }
        int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>>q;
        q.push({0,0});
        vis[0][0] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto coord = q.front();
                q.pop();
                int x = coord.first;
                int y = coord.second;
                if(x == m-1 && y == n-1){
                    return ans+1;
                }
                for(int k=0;k<8;k++){
                    int nextx = x+dir[k][0];
                    int nexty = y+dir[k][1];
                    if(nextx >= 0 && nexty >= 0 && nextx < m && nexty < n && !vis[nextx][nexty] && grid[nextx][nexty] == 0 ){
                        vis[nextx][nexty] = true;
                        q.push({nextx, nexty});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};