class Solution {
public:
    int strStr(string a, string b) {
        int l=0 , r=0, n=a.size(), sz=b.size(), ans=-1;
        while(r<n){
            if(a[r]==b[l]){
                ans=r;
                while(l<sz && r<n && a[r]==b[l]){r++; l++;}
                if(l==sz){return ans;}
                r=ans+1; l=0; ans=-1;
            } else {
                r++; l=0; ans=-1;
            }
        }
        return -1;
    }
};