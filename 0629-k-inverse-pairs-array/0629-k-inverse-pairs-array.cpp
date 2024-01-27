class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1e9+7;
        vector<int> curr(k+1,0), prev(k+1,0);
        prev[0]=1;
        for(int i=1 ; i<=n ; i++){
            int sum=0;
            for(int j=0; j<=k ; j++){
                if(j>=i){sum = (sum-prev[j-i]+mod)%mod;}
                sum = (sum+prev[j])%mod;
                curr[j] = sum;
            }
            prev=curr;
        }
        return prev[k];
    }
};