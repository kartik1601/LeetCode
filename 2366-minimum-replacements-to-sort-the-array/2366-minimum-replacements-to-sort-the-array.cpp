class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]>nums[i+1]){
                //break nums[i] into smaller parts
                long long no_int = ceil((nums[i]+nums[i+1]-1LL)/nums[i+1]);
                ans += no_int - 1;
                nums[i] = nums[i]/no_int;
            }
        }

        return ans;
    }
};