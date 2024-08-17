#define ll long long
#define F  first
#define S  second

class Solution {
public:
    ll dp[502][502];
    ll rec(int r,int c1,int c2,vector<vector<pair<ll,int>>>&f){
        if(r==f.size()) {return -1e18;}
        if(dp[r][c1+1]!=-1) {return dp[r][c1+1];}
    
        ll ans = rec(r+1,c1,c2,f);
        
        for(int col=0; col<3; col++){
            if(f[r][col].S!=c2 && f[r][col].S!=c1){
                if(c1!=-1){
                    ans = max(ans,f[r][col].F);
                } else {
                    ans = max(ans,f[r][col].F + rec(r+1,f[r][col].S,c2,f));
                }
            }
        }
        
        return dp[r][c1+1]=ans;
    }
    ll maximumValueSum(vector<vector<int>>& b) {
        int m=b.size(), n=b[0].size();
        vector<vector<pair<ll,int>>> f(m,vector<pair<ll,int>>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                f[i][j]=make_pair(b[i][j],j);
            }
        }
        
        for(int i=0; i<m; i++){
            sort(f[i].rbegin(), f[i].rend());
        }
        sort(f.rbegin(), f.rend());
        
		ll ans=-1e18;
        for(int col=0; col<3; col++){
            memset(dp,-1,sizeof(dp));
            ans = max(ans, f[0][col].F + rec(1,-1,f[0][col].S,f));
        }
        return ans;
    }
};