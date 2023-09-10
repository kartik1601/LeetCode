class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //hashing
        unordered_map<int,int> mp;
        for(int x : nums){
            if(mp.find(x)!=mp.end())    return true;
            mp[x]++;
        }
        return false;
    }
};