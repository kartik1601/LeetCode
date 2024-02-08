class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxJump=0;
        
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(mxJump<i){return false;}
            mxJump = max(mxJump,i+nums[i]);
            // i denotes the jumps till i-th pos
        }
        
        return mxJump>=nums.size()-1;
    }
};