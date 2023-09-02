class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        unordered_map<int, int> mp;
        
        return rec(s,mp,dict,0,n);
    }
    int rec(string&s,unordered_map<int, int>&mp,unordered_set<string>&dict,int start,int n){
            if (start == n) {
                return 0;
            }
            if (mp.count(start)) {
                return mp[start];
            }
            int ans = rec(s,mp,dict,start + 1,n) + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dict.count(curr)){
                    ans = min(ans, rec(s,mp,dict,end + 1,n));
                }
            }

            return mp[start] = ans;
        }
};