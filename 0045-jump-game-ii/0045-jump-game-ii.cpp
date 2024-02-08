class Solution {
public:
    int jump(vector<int>& nums) {
        int mnJumps=0, curr=0, far=0;
        
        for(int i=0 ; i<nums.size()-1 ; i++){
            far = max(far,i+nums[i]);
            if(i==curr){mnJumps++; curr=far;}
        }
        
        return mnJumps;
    }
};