class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> freq;
        for(int&num:arr){freq[num]++;}
        vector<int> f;
        for(auto&[c,n]:freq){f.push_back(n);}
        sort(f.begin(),f.end());
        
        int ans=f.size();
        for(auto&n:f){
            k-=n; ans--;
            if(k==0){return ans;}
            if(k<0){return ans+1;}
        }
        return ans;
    }
};