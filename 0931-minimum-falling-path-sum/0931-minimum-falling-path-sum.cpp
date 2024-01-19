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
        
        int dir[3] = {-1,0,1};
        for(int i=0 ; i<3 ; i++){
            int c = col+dir[i];
            if(c<mat.size() && c>=0){
                dp[row][col] = min(dp[row][col],mat[row][col]+memo(row+1,c,mat,dp));
            }
        }
        return dp[row][col];
    }
};