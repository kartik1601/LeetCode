class Solution {
public:
    int countSubstrings(string s) {
        int res=0, n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=0 ; l<n ; l++){
            for(int r=l ; r<n ; r++){
                res += memo(s,l,r,dp);
            }
        }
        return res;
    }
    int memo(string&s,int l,int r,vector<vector<int>>&dp){
        if(l>=r){return 1;}
        if(dp[l][r]){return dp[l][r];}
        
        return dp[l][r] = s[l]==s[r] ? memo(s,l+1,r-1,dp) : 0;
    }
};