class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        
        return memo(0,nums,dp);
    }
    int memo(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==nums.size()-1){return 1;}
        if(nums[idx]==0){return dp[idx]=0;}
        if(dp[idx]!=-1){return dp[idx];}
        
        for(int jump=nums[idx]; jump>0; jump--){
            if(idx+jump>nums.size()-1){continue;}
            dp[idx] = memo(idx+jump,nums,dp);
            if(dp[idx]){return dp[idx];}
        }
        return dp[idx];
    }
};