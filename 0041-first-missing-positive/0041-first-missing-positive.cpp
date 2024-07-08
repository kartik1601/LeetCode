class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int one=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1){one=1;}
            else if(nums[i]<=0 || nums[i]>n){nums[i]=1;}
        }

        if(!one){return 1;}

        for(int i=0 ; i<n ; i++){
            int val = abs(nums[i]);
            if(nums[val%n]>0){nums[val%n] *= -1;}
        }

        for(int i=1 ; i<n ; i++){
            if(nums[i]>0){return i;}
        }
        
        return nums[0]>0 ? n : n+1;
    }
};