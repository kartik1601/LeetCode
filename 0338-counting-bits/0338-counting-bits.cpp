class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int num=0 ; num<=n ; num++){
            int cnt=0;
            for(int i=0 ; i<31 ; i++){
                if((num>>i)&1) cnt++;
            }
            ans[num]=cnt;
        }
        return ans;
    }
};