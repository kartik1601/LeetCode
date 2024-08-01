class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wV, vector<vector<int>>& f, int id, int lvl) {
        vector<int> vis(f.size(),0);
        queue<int> q;
        q.push(id); vis[id]=1;

        while(!q.empty()){
            int sz = q.size(); lvl-=1;
            while(sz--){
                int node = q.front(); q.pop();
                for(auto&nbr:f[node]){
                    if(!vis[nbr]){
                        vis[nbr]=1;
                        q.push(nbr);
                    }
                }
            }
            if(!lvl){break;}
        }

        vector<string> res;
        unordered_map<string,int> freq;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto&vid:wV[node]){
                freq[vid]++;
                if(freq[vid]==1){res.push_back(vid);}
            }
        }

        sort(res.begin(),res.end(),[&](string s1,string s2){
            if(freq[s1]==freq[s2]){return s1<s2;}
            return freq[s1]<freq[s2];
        });

        return res;
    }
};