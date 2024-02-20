class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(), sum=accumulate(nums.begin(),nums.end(),0);
        return abs(n*(n+1)/2 - sum);
    }
};