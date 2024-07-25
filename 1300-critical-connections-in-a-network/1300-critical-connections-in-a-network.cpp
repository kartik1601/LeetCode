class Solution {
    int t=1;
public:
    void dfs(vector<vector<int>>&g,int node,int parent,vector<int>&vis,
    vector<int>&curDepth, vector<int>&minDepth,vector<vector<int>>&res){
        vis[node]=1;
        curDepth[node] = minDepth[node] = t;
        t++;

        for(auto&nbr:g[node]){
            if(nbr==parent){continue;}
            if(!vis[nbr]){
                dfs(g,nbr,node,vis,curDepth,minDepth,res);
                minDepth[node] = min(minDepth[node], minDepth[nbr]);
                if(minDepth[nbr] > curDepth[node]){
                    res.push_back({node,nbr});
                }
            } else {
                minDepth[node] = min(minDepth[node], minDepth[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn){
        vector<vector<int>> graph(n);
        for(auto&c:conn){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<int> vis(n,0), curDepth(n,0), minDepth(n,0);
        vector<vector<int>> res;
        dfs(graph,0,-1,vis,curDepth,minDepth,res);
        return res;
    }
};