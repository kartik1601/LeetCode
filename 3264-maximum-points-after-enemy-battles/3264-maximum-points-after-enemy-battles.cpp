class Solution {
public:
    long long maximumPoints(vector<int>& e, int curr) {
        long long res=0LL;
        int n=e.size() , mn=*min_element(e.begin(),e.end());
        
        if(curr<mn){return 0;}

        bool c=true;
        for(int i=0;i<n;i++){
            if(c && e[i]==mn){
                c=false;
                continue;
            }
            curr+=e[i];
            res+=curr/mn;
            curr%=mn;
        }
        while(curr>=mn){
            res+=curr/mn;
            curr%=mn;
        }
        return res;
    }
};