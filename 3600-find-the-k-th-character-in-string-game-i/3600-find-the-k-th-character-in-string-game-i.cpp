class Solution {
public:
    char kthCharacter(int k) {
        string initial = "a";
        while(initial.length() <= k){
            string temp = initial;
            for(int i=0; i<temp.length(); i++){
                char next = 'a' + (temp[i] - 'a' + 1) % 26;
                initial = initial + next;
            }
        }
        return initial[k-1];
    }
};