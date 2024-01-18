class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return memo(n,dp);
    }
    int memo(int step, vector<int>&dp){
        if(step==0){return 1;}
        if(step<0){return 0;}
        
        if(dp[step]!=-1){return dp[step];}
        
        return dp[step] = memo(step-1,dp) + memo(step-2,dp);
    }
};