class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(), e=0,o=1;
        vector<int> ans(n,0);
        for(auto&num:nums){
            if(num>0){ans[e]=num; e+=2;}
            else{ans[o]=num; o+=2;}
        }
        return ans;
    }
};