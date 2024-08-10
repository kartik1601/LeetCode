class Solution {
public:
    int findRadius(vector<int>& hs, vector<int>& ht) {
        int n=ht.size(), h=hs.size(), res=0;
        sort(ht.begin(),ht.end());

        for(int i=0 ; i<h ; i++){
            auto it = lower_bound(ht.begin(),ht.end(),hs[i]);
            int r = (it==ht.end()) ? INT_MAX : *it-hs[i];
            int l = (it==ht.begin()) ? INT_MAX : hs[i] - *(--it);
            res = max(res,min(l,r));
        }

        return res;
    }
};