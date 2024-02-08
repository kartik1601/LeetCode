class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        vector<long long> dp(n,INT_MAX);
        
        return memo(0,nums,dp);
    }
    int memo(int idx,vector<int>&nums,vector<long long>&dp){
        if(idx==nums.size()-1){return 0;}
        if(nums[idx]==0){return dp[idx];}
        if(dp[idx]!=INT_MAX){return dp[idx];}
        
        for(int j=nums[idx] ; j>0 ; j--){
            if(idx+j>nums.size()-1){continue;}
            dp[idx] = min(dp[idx],1LL+memo(idx+j,nums,dp));
        }
        return dp[idx];
    }
};