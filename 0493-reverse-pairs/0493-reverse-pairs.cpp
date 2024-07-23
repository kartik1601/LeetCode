class Solution {
    int res=0;
public:
    void merge(vector<int>&ni,int s,int m,int e){
        vector<int> temp;
        int i=s, j=m+1;

        while(i<=m && j<=e){
            if(ni[i] <= 2*(long)ni[j]){
                j++;
            } else {
                res += (e-j+1);
                i++;
            }
        }

        i=s, j=m+1;
        while(i<=m && j<=e){
            if(ni[i]<=ni[j]){
                temp.push_back(ni[j++]);
            } else {
                temp.push_back(ni[i++]);
            }
        }
        while(i<=m){temp.push_back(ni[i++]);}
        while(j<=e){temp.push_back(ni[j++]);}

        for(int l=s ; l<=e ; l++){ni[l]=temp[l-s];}
    }
    void mergeSort(vector<int>&ni,int s,int e){
        if(s>=e){return;}
        int m=s+(e-s)/2;
        mergeSort(ni,s,m);
        mergeSort(ni,m+1,e);
        merge(ni,s,m,e);
    }
    int reversePairs(vector<int>& nums) {
        vector<int> ni;
        for(int i=0 ; i<nums.size() ; i++){ni.push_back(nums[i]);}
        mergeSort(ni,0,nums.size()-1);
        return res;
    }
};