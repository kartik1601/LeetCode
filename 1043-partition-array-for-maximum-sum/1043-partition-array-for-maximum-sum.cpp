class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return memo(0,arr,k,dp);
    }
    int memo(int i, vector<int>&arr, int k,vector<int>&dp){
        if(i>=arr.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        
        int mx_ele=INT_MIN;
        for(int j=i; j<min((int)arr.size(),i+k) ; j++){
            mx_ele = max(mx_ele,arr[j]);
            int currSum = mx_ele * (j-i+1);
            dp[i] = max(dp[i],memo(j+1,arr,k,dp)+currSum);
        }
        return dp[i];
    }
};