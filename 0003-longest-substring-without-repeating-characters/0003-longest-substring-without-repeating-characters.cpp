class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0 , r=0, res=0;
        unordered_map<char,int> freq;

        while(r<s.size()){
            freq[s[r]]++;
            
            while(freq[s[r]]>1){
                freq[s[l++]]--;
            }
            
            res = max(res,r-l+1);
            r++;
        }

        return res;
    }
};