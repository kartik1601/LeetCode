class Solution {
public:
    string convert(string s, int n) {
        int diff=2*(n-1), d1=diff, d2=0, sz=s.size();
        if(n==1){return s;}
        
        string res;
        for(int i=0 ; i<n ; i++){
            int idx=i; 
            if(idx==0 || idx==n-1){
                while(idx<sz){res+=s[idx]; idx+=diff;}
            } else {
                d1-=2; d2+=2;
                int flag=0;
                while(idx<sz){
                    res += s[idx];
                    if(flag%2==0){idx+=d1;}
                    else {idx+=d2;}
                    flag+=1;
                }
            }
        }
        return res;
    }
};