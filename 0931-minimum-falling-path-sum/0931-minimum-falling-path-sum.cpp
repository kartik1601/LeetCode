class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> curr(n,INT_MAX), next(n,0);
        int ans=INT_MAX;
        for(int r=n-1 ; r>=0; r--){
            for(int c=0 ; c<n ; c++){
                int res=INT_MAX;
                if(c-1>=0){res=min(res,next[c-1]);}
                if(c  >=0){res=min(res,next[c]);}
                if(c+1< n){res=min(res,next[c+1]);}
                curr[c] = mat[r][c] + res;
                if(!r){ans = min(ans,curr[c]);}
            }
            next=curr;
        }
        
        return ans;
    }
};