class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int mp[2001]={0};
        for(int num:arr){mp[num+1000]++;}
        int freq[1001]={0};
        for(int c:mp){if(c!=0 && freq[c]==1){return false;}; freq[c]=1;}
        return true;
    }
};