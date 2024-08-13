class Solution {
public:
    set<vector<int>> vis;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        for(int num : c){
            if(num>t){continue;}
            vector<int> temp;
            temp.push_back(num);
            rec(t-num,temp,c);
        }
        return res;
    }
    void rec(int sum,vector<int>&v,vector<int>&c){
        if(sum==0){
            auto temp = v;
            sort(temp.begin(),temp.end());
            if(vis.find(temp)==vis.end()){
                res.push_back(v);
                vis.insert(temp);
            }
            return;
        }

        for(int num : c){
            if(num>sum){continue;}
            v.push_back(num);
            rec(sum-num,v,c);
            v.pop_back();
        }
    }
};