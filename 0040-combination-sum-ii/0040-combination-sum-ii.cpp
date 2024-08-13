class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int> temp;
        for(int i=0 ; i<(int)c.size() ; i++){
            if(c[i]>t){break;}
            if(i>0 && c[i-1]==c[i]){continue;}
            temp.push_back(c[i]);
            rec(t-c[i],i,temp,c);
            temp.pop_back();
        }
        return res;
    }
    void rec(int sum,int idx,vector<int>&v,vector<int>&c){
        if(sum==0){res.push_back(v); return;}

        for(int i=idx+1 ; i<(int)c.size() ; i++){
            if(c[i]>sum){break;}
            if(i>idx+1 && c[i-1]==c[i]){continue;}
            v.push_back(c[i]);
            rec(sum-c[i],i,v,c);
            v.pop_back();
        }
    }
};