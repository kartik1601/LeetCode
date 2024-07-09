class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0, n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        unordered_map<int,int> mp;
        
        for(int i=1; i<n ; i++){
            pref[i]=pref[i-1]+nums[i];
        }

        for(int i=0 ; i<n ; i++){
            if(pref[i]==k){cnt++;}
            if(mp.find(pref[i]-k)!=mp.end()){
                cnt+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        
        return cnt;
    }
};