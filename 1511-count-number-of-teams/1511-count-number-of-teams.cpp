class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size(), res=0;

        for(int j=1 ; j<n-1 ; j++){
            int l_s=0,l_b=0,r_s=0,r_b=0;
            for(int l=0 ; l<j ; l++){
                if(nums[l]<nums[j]){l_s++;}
                if(nums[l]>nums[j]){l_b++;}
            }
            for(int r=j+1 ; r<n ; r++){
                if(nums[r]<nums[j]){r_s++;}
                if(nums[r]>nums[j]){r_b++;}
            }
            res += (l_s * r_b) + (l_b * r_s);
        }
        return res;
    }
};