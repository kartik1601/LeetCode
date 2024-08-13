class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        for(int idx=0 ; idx<(int)c.size() ; idx++){
            if(c[idx]>t){break;}
            vector<int> temp;
            temp.push_back(c[idx]);
            rec(t-c[idx],idx,temp,c);
        }
        return res;
    }
    void rec(int sum,int idx,vector<int>&v,vector<int>&c){
        if(sum==0){
            res.push_back(v);
            return;
        }

        for(int i=idx ; i<(int)c.size() ; i++){
            if(c[i]>sum){break;}
            v.push_back(c[i]);
            rec(sum-c[i],i,v,c);
            v.pop_back();
        }
    }
};