class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0, j=nums[n-1];
        while(i<j){
            int m = i+(j-i)/2;
            int cnt=0,l=0;

            for(int r=0 ; r<n ; r++){
                while(l<r && nums[r]-nums[l]>m){l++;}
                cnt += r-l;
            }

            if(cnt>=k){j=m;}
            else{i=m+1;}
        }

        return i;
    }
};