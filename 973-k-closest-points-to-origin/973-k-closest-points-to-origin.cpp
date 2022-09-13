class Solution {
public:
    typedef pair<int,pair<int,int>> node;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<node, vector<node>, greater<node>> pq;
        vector<vector<int>> result;
        
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            int dist = x*x + y*y;
            
            pq.push(make_pair(dist, make_pair(x, y)));
            
        }
        
        while(k--) {
            node p = pq.top();
            pq.pop();
            result.push_back({ p.second.first, p.second.second });                
        }
        
        return result;
    }
};