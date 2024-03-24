class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=1, e=nums.size()-1;
        
        while(s<e){
            int mid = (e-s)/2+s;
            int cnt=0;
            
            for(int num:nums){if(num<=mid){cnt++;}}
            if(cnt>mid){e=mid;}
            else{s=mid+1;}
        }
        
        return s;
    }
};