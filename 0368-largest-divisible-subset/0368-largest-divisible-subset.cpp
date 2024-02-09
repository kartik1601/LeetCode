class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> curr(n,1), prev(n,-1);
        
        int mx=0, mxIdx= -1;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[j]%nums[i]==0 && curr[j]<curr[i]+1) {
                    curr[j]=curr[i]+1;
                    prev[j]=i;
                }
            }
            if(curr[i]>mx){
                mx=curr[i];
                mxIdx=i;
            }
        }
        
        vector<int> res;
        for (int j=mxIdx; j!=-1; j=prev[j]) {
            res.push_back(nums[j]);
        }
        return res;
    }
    
};