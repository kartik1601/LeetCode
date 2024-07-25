class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res=nums;
        mergeSort(res,0,res.size()-1);
        return res;
    }
    void mergeSort(vector<int>&nums,int s,int e){
        if(s>=e){return;}
        int m=s+(e-s)/2;
        mergeSort(nums,s,m);
        mergeSort(nums,m+1,e);

        int i=s, j=m+1;
        vector<int> temp;
        while(i<=m && j<=e){
            if(nums[i]<=nums[j]){temp.push_back(nums[i++]);}
            else{temp.push_back(nums[j++]);}
        }

        while(i<=m){temp.push_back(nums[i++]);}
        while(j<=e){temp.push_back(nums[j++]);}

        for(int k=s ; k<=e ; k++){nums[k] = temp[k-s];}
    }
};