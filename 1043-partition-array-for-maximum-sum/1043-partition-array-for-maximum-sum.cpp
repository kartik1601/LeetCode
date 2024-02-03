class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1 ; i>=0 ; i--){
            int mx=INT_MIN;
            for(int j=i; j<min(n,i+k) ; j++){
                mx = max(mx,arr[j]);
                dp[i] = max(dp[i],dp[j+1]+mx*(j-i+1));
            }
        }
        return dp[0];
    }
};