class Solution {
public:
    int xorOperation(int n, int start) {
        int xori = start;
        for(int i=1;i<n;i++){
            xori = xori^(start+2*i);
        }
        return xori;
    }
};