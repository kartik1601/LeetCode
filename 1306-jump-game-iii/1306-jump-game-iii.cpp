class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        set<int> vis;
        return memo(start,arr,vis);
    }
    bool memo(int idx,vector<int>&nums,set<int>&vis){
        if(nums[idx]==0){return true;}
        
        vis.insert(idx);
        bool w1=false, w2=false;
        if(idx-nums[idx]>=0 && vis.find(idx-nums[idx])==vis.end()){
            w1=memo(idx-nums[idx],nums,vis);
        }
        if(idx+nums[idx]<nums.size() && vis.find(idx+nums[idx])==vis.end()){
            w2=memo(idx+nums[idx],nums,vis);
        }
        
        return w1 || w2;
    }
};