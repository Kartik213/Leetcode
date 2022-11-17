class Solution {
public:
    int fib(int n){
        if(n<=2)
            return n;
        int first = fib(n-1);
        int second = fib(n-2);
        return(first + second);
    }
    int climbStairs(int n) {
        
        //Basically fibonanacci problem
        //f(n) = f(n-1) + f(n-2);
        // return fib(n);
        
        if (n <= 2) return n;
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++) {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};