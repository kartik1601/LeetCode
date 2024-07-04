class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0, mx=nums[n-1];
        
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]<mx){mx=nums[i]; cnt++;}
            if(cnt==2){break;}
        }
        return cnt<2 ? nums[n-1] : mx;
    }
};