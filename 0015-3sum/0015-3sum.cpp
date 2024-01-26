class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i<nums.size()-2 ; i++){
            if(i>0 && nums[i-1]==nums[i]){continue;}
            int x = -1*nums[i];
            int s=i+1 , e=nums.size()-1;
            while(s<e){
                int sum = nums[s]+nums[e];
                if(sum==x){
                    int F=nums[s],S=nums[e];
                    ans.push_back({nums[i],F,S});
                    while(s<e && nums[s]==F){s++;}
                    while(s<e && nums[e]==S){e--;}
                    
                } else if(sum < x) {
                    s+=1;
                } else {
                    e-=1;
                }
            }
        }
        return ans;
    }
};