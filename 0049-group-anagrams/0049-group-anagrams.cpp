class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        
        for(string&str:strs){
            string temp=str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        
        for(auto&[s,v]:mp){res.push_back(v);}
        
        return res;
    }
};