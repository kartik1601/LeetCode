class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){intersection(nums2,nums1);}
        sort(nums2.begin(),nums2.end());
        set<int> s;
        for(int num:nums1){s.insert(num);}
        vector<int> ans;
        
        for(int num:s){
            int l=0, r=nums2.size()-1;
            while(l<=r){
                int mid = (r-l)/2+l;
                if(nums2[mid]==num){ans.push_back(num); break;}
                else if(nums2[mid]>num){r=mid-1;}
                else{l=mid+1;}
            }
        }
        
        return ans;
    }
};