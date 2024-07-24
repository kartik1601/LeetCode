class Solution {
    bool flag = false;
public:
    double dfs(unordered_map<string,vector<pair<string,double>>>&adj,string src,string des,unordered_map<string,int>&vis){
        if(src==des){flag=true; return (double)1;}

        double res = -1;
        for(auto&v : adj[src]){
            if(flag){break;}
            if(vis.find(v.first)==vis.end()){
                vis[v.first] = 1;
                res = v.second * dfs(adj,v.first,des,vis);
            }
        }
        return flag ? res : -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>&eq,vector<double>&val,vector<vector<string>>&qu) {
        unordered_map<string,int> exists;
        unordered_map<string,vector<pair<string,double>>> adj;
        int i=0;
        for(auto&v:eq){
            exists[v[0]]++; exists[v[1]]++;
            adj[v[0]].push_back({v[1],val[i]});
            adj[v[1]].push_back({v[0],(double)1/val[i]});
            i++;
        }

        vector<double> res;
        for(auto&q:qu){
            if(!exists.count(q[0]) || !exists.count(q[1])){
                res.push_back(double(-1));
            } else {
                unordered_map<string,int> vis;
                vis[q[0]] = 1; flag = false;
                res.push_back(dfs(adj,q[0],q[1],vis));
            }
        }

        return res;
    }
};