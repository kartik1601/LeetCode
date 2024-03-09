class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){swap(nums1,nums2);}
        int n=nums1.size(), m=nums2.size();
        
        for(int i=0 ; i<n ; i++){
            int target = nums1[i], l=0, r=m-1;
            while(l<=r){
                int mid=(r-l)/2+l;
                if(nums2[mid]==target){return target;}
                else if(nums2[mid]>target){r=mid-1;}
                else{l=mid+1;}
            }
        }
        
        return -1;
    }
};