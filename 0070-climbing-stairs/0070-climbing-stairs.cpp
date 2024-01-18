class Solution {
public:
    int climbStairs(int n) {
        int ans=1, p=1, pp=1;
        for(int i=2 ; i<=n ; i++){
            ans = p + pp;
            pp=p;
            p=ans;
        }
        return ans;
    }
};