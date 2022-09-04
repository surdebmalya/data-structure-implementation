class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int prev2=1, prev1=2;
        for(int i=3; i<=n; i++) {
            int temp = prev1;
            prev1 += prev2;
            prev2=temp;
        }
        return prev1;
    }
};