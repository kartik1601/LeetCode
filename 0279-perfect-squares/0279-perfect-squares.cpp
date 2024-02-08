class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while(dp.size()<=n){
            int x=dp.size(), curr=INT_MAX;
            for(int i=1 ; i*i<=x ; i++){
                curr = min(curr,1+dp[x-i*i]);
            }
            dp.push_back(curr);
        }
        return dp[n];
    }
};