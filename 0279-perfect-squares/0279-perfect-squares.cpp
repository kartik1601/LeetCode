class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        return memo(n,dp);
    }
    int memo(int n,vector<int>&dp){
        if(n<=0){return 0;}
        if(dp[n]!=INT_MAX){return dp[n];}
        
        for(int i=1 ; i*i<=n ; i++){
            dp[n]=min(dp[n],1+memo(n-i*i,dp));
        }
        return dp[n];
    }
};