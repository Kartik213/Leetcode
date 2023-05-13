class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i+1);
        }
        while(q.size() != 1){
            int i=1;
            while(i<k){
                int temp = q.front();
                q.pop();
                q.push(temp);
                i++;
            }
            q.pop();
        }
        return q.front();
    }
};