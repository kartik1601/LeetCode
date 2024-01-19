class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n+1,vector<int>(n,INT_MAX));
        for(int i=0 ; i<n ; i++){dp[n][i]=0;}
        int ans=INT_MAX;
        for(int r=n-1 ; r>=0; r--){
            for(int c=0 ; c<n ; c++){
                int res=INT_MAX;
                if(c-1>=0){res=min(res,dp[r+1][c-1]);}
                if(c  >=0){res=min(res,dp[r+1][c]);}
                if(c+1< n){res=min(res,dp[r+1][c+1]);}
                dp[r][c] = mat[r][c] + res;
                if(!r){ans = min(ans,dp[r][c]);}
            }
        }
        
        return ans;
    }
};