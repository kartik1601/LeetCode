class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            ans = max(ans,memo(i,nums,dp));
        }
        return ans;
    }
    int memo(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==nums.size()-1){return 1;}
        if(dp[idx]!=-1){return dp[idx];}

        int maxLen=1;
        for(int i=idx+1; i<nums.size() ; i++){
            if(nums[i]>nums[idx]){
                maxLen = max(maxLen,1+memo(i,nums,dp));
            }
        }

        return dp[idx]=maxLen;
    }
};