class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(), res=0, lcl_mx=0;
        vector<int> l(n,0), r(n,0);

        for(int i=0 ; i<n ; i++){
            lcl_mx = max(lcl_mx , h[i]);
            l[i] = lcl_mx;
        }

        lcl_mx = 0;
        for(int i=n-1 ; i>=0 ; i--){
            lcl_mx = max(lcl_mx, h[i]);
            r[i] = lcl_mx;
        }

        for(int i=0 ; i<n ; i++){
            res += min(l[i],r[i]) - h[i];
        }

        return res;
    }
};