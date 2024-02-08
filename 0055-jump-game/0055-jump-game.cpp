class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[n-1]=1;
        
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=nums[i]; j>0; j--){
                if(i+j>n-1){continue;}
                dp[i] = dp[i+j];
                if(dp[i]){break;}
            }
        }
        
        return dp[0];
    }
};