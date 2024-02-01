class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        int idx=0;
        for(int i=0 ; i<n/3 ; i++){
            int x=nums[idx], y=nums[idx+1], z=nums[idx+2];
            if(z-x<=k){
                ans.push_back({x,y,z});
                idx+=3;
            } else {return {};}
        }
        return ans;
    }
};