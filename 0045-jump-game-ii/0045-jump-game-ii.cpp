class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        vector<long long> dp(n,INT_MAX);
        dp[n-1]=0;
        
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=nums[i] ; j>0 ; j--){
                if(i+j>n-1){continue;}
                dp[i] = min(dp[i],1+dp[i+j]);
            }
        }
        
        return dp[0];
    }
};