class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        vector<pair<int,int>> v;
        for(int i=0 ; i<m ; i++){
            auto& temp = arrays[i];
            v.push_back({temp[0],i});
            v.push_back({temp[temp.size()-1],i});
        }

        sort(v.begin(),v.end());

        return rec(0,v.size()-1,v);
    }
    int rec(int l,int r,vector<pair<int,int>>&v){
        if(l>=r){return -1;}

        if(v[l].second != v[r].second){
            return v[r].first - v[l].first;
        }

        return max(rec(l+1,r,v),rec(l,r-1,v));
    }
};