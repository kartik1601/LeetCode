class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num:arr){mp[num]++;}
        int freq[1001]={0};
        for(auto&[n,c]:mp){if(freq[c]==1){return false;}; freq[c]=1;}
        return true;
    }
};