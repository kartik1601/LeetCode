class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int)strs.size();
        vector<vector<string>> res;
        unordered_map<string,int> mp;
        int i=0;

        for(string s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                res[mp[temp]].push_back(s);
            } else {
                mp[temp] = i++;
                res.push_back({s});
            }
        }

        return res;
    }
};