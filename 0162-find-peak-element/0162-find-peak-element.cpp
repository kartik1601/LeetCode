class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0 , r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int left = mid>0 ? nums[mid-1] : INT_MIN;
            int right = mid<n-1 ? nums[mid+1] : INT_MIN;
            if(left<nums[mid] && right<nums[mid]){return mid;} 
            else if(left>nums[mid]){r=mid-1;}
            else{l=mid+1;}
        }
        return 0;
    }
};