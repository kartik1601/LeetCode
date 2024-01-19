class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0 ; i<n; i++){ans = min(ans,memo(0,i,matrix,dp));}
        return ans;
    }
    int memo(int row, int col , vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(row==mat.size()){return 0;}
        if(dp[row][col]!=INT_MAX){return dp[row][col];}
        
        int res=INT_MAX;
        if(col-1>=0){res=min(res,mat[row][col]+memo(row+1,col-1,mat,dp));}
        if(col  >=0){res=min(res,mat[row][col]+memo(row+1,col ,mat,dp));}
        if(col+1<mat.size()){res=min(res,mat[row][col]+memo(row+1,col+1,mat,dp));}
        return dp[row][col]=res;
    }
};