class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        
        unordered_map<string,vector<int>> pos;
        for(int i=0 ; i<n ; i++) {
            string str = strs[i];
            sort(str.begin(),str.end());
            pos[str].push_back(i);
        }
        
        for(auto &p : pos){
            vector<string> res;
            for(int idx : p.second)
                {res.push_back(strs[idx]);}
            ans.push_back(res);
        }
        
        return ans;
    }
};