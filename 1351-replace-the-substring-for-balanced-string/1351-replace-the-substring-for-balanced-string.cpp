class Solution {
public:
    int balancedString(string s) {
        int r=0, l=0, n=s.size(), res=INT_MAX, t=n/4;
        unordered_map<char,int> freq;
        for(char&c:s){freq[c]++;}
        
        while(r<n){
            freq[s[r]]--;
            while(l<n && freq['Q']<=t && freq['W']<=t && freq['E']<=t && freq['R']<=t){
                res = min(res,r-l+1);
                freq[s[l++]]++;
            }
            r++;
        }
        return res;
    }
};