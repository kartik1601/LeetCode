class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,res=0;
        for(int num:nums){
            if(!cnt){res=num;}
            if(num==res){cnt++;}
            else{cnt--;}
        }
        return res;
    }
};