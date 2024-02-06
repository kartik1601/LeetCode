class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1, cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n ; i++){
            if(nums[i]!=cnt){return false;}
            cnt++;
        }
        return n>0 && nums[n-1]==nums[n];
    }
};