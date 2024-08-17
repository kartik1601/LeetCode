class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        vector<int> nums = arr;
        int n=nums.size(), l=0 , r=1, maxLen=1;
        if(!n){return 0;}
        sort(nums.begin(),nums.end());
        nums.resize(unique(nums.begin(),nums.end())-nums.begin());

        while(r<n){
            while(r<n && nums[r-1]+1==nums[r]){r++;}
            maxLen = max(maxLen,r-l);
            l=r; r++;
        }

        return maxLen;
    }
};