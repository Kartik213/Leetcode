class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        // Brute Force
        // int op = 0;
        // for(auto it:logs){
        //     if(it == "./")
        //         op = op;
        //     else if(it == "../" && op >= 1)
        //         op--;
        //     else if(it != "../" && it != "./")
        //         op++;
        // }
        // return op;
        
        
        //Using Stack
        stack<string>st;
        for(int i=0;i<logs.size();i++){
            string str = logs[i];
            if(str == "../"){
                if(!st.empty())
                    st.pop();
            }
            else if(str != "./")
                st.push(str);
        }
        return st.size();
    }
};