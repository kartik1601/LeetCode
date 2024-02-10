class Solution {
public:
    int countSubstrings(string s) {
        int res=0, n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=n-1 ; l>=0 ; l--){
            for(int r=l ; r<n ; r++){
                if(l==r){
                    dp[l][r]=1;
                } else if(l+1==r){
                    dp[l][r] = s[l]==s[r] ? 1 : 0;
                } else {
                    dp[l][r] = s[l]==s[r] ? dp[l+1][r-1] : 0;
                }
                
                res += dp[l][r];
            }
        }
        return res;
    }
};