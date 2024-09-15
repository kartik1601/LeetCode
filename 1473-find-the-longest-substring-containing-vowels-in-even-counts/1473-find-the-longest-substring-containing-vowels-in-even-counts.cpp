class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = (int)s.size(), maxLen = 0, i = 0;

        auto isVowel = [&](char ch) -> bool {
            return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
        };
        
        bitset<26> mask;
        unordered_map<unsigned long,int> maskIdx;
        maskIdx[0L] = -1;
        for(; i<n ; i++){
            if(isVowel(s[i])){
                mask[s[i]-'a'] = mask[s[i]-'a'] ^ 1;
                if(!maskIdx.count(mask.to_ulong())){
                    maskIdx[mask.to_ulong()] = i;
                }
            }
            maxLen = max(maxLen , i-maskIdx[mask.to_ulong()]);
        }

        return maxLen;
    }
};