class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(k,0);
        dp[0]=arr[0];
        for(int i=1 ; i<n ; i++){
            int mx=INT_MIN , ans=INT_MIN;
            for(int j=i ; j>max(-1,i-k) ; j--){
                mx = max(mx,arr[j]);
                int subSum = j>0 ? dp[(j-1)%k] : 0;
                ans = max(ans,subSum+mx*(i-j+1));
            }
            dp[i%k] = ans;
        }
        return dp[(n-1)%k];
    }
};