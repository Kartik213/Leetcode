class Solution {
public:
    int minOperations(vector<string>& logs) {
        int op = 0;
        for(auto it:logs){
            if(it == "./")
                op = op;
            else if(it == "../" && op >= 1)
                op--;
            else if(it != "../" && it != "./")
                op++;
        }
        return op;
    }
};