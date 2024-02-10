class Solution {
public:
    int countSubstrings(string s) {
        int res=0, n=s.size();
        
        for(int l=0 ; l<n ; l++){
            // even length string + odd length string
            res += solve(l,l,s) + solve(l,l+1,s);
        }
            
        return res;
    }
    int solve(int l, int r, string&s){
        int res=0;
        while(l>=0 && r<=s.size()-1){
            if(s[l]==s[r]){res++;}
            else{break;}
            l--; r++;
        }
        return res;
    }
};