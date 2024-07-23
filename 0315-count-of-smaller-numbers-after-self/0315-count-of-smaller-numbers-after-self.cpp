class Solution {
    vector<int> res;
public:
    void merge(vector<pair<int,int>>&ni,int s,int m,int e){
        vector<pair<int,int>> temp;
        int l=s, r=m+1, cnt=0;

        while(l<=m && r<=e){
            if(ni[l].first <= ni[r].first){
                temp.push_back(ni[r++]); // desc order
            } else {
                res[ni[l].second] += (e-r+1);
                temp.push_back(ni[l++]);
            }
        }

        while(l<=m){temp.push_back(ni[l++]);}
        while(r<=e){temp.push_back(ni[r++]);}

        for(int i=s ; i<=e ; i++){ni[i]=temp[i-s];}
    }
    void mergeSort(vector<pair<int,int>>&ni,int s,int e){
        if(s>=e){return;}
        int m = (e-s)/2+s;
        mergeSort(ni,s,m);
        mergeSort(ni,m+1,e);

        merge(ni,s,m,e);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> ni;
        for(int i=0 ; i<nums.size() ; i++){ni.push_back({nums[i],i});}
        res.resize(nums.size(),0);
        mergeSort(ni,0,ni.size()-1);
        return res;
    }
};