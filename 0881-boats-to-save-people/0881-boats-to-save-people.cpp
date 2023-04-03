class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int right = people.size()-1;
        int left = 0;
        int res = 0;
        // while(left <= right){
        //     if(people[right] == limit){
        //         res++;
        //         right--;
        //     }
        //     else if(people[right] + people[left] > limit){
        //         res++;
        //         right--;
        //     }
        //     else{
        //         res++;
        //         right--;
        //         left++;
        //     }
        // }
        while(left <= right){
            if(people[right] + people[left] <= limit){
                res++;
                right--;
                left++;
            }
            else{
                res++;
                right--;
            }
        }
        return res;
    }
};