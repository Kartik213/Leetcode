class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int freshOranges = 0;
        int res = -1;
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto coord = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nextx = coord.first + dir[k][0];
                    int nexty = coord.second + dir[k][1];
                    if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == 1){
                        grid[nextx][nexty] = 2;
                        freshOranges--;
                        q.push({nextx, nexty});
                    }
                }
            }
            res++;
        }
        if(freshOranges > 0){
            return -1;
        }
        return res;
    }
};