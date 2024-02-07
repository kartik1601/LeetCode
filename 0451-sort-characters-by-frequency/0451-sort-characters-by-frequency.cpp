class Solution {
    using pci = pair<int,char>;
public:
    string frequencySort(string s) {
        priority_queue<pci> pq;
        unordered_map<char,int> mp;
        
        for(char&c:s){mp[c]++;}
        for(auto&[c,n]:mp){pq.push({n,c});}
        
        string res;
        while(!pq.empty()){
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(cnt--){res+=ch;}
        }
        return res;
    }
};