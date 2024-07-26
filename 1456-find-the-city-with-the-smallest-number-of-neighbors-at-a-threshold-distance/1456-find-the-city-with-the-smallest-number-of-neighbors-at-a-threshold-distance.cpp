class Solution {
    using pii = pair<int,int>;
    int res=-1, mn_size=INT_MAX;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pii>> adj(n);
        for(auto&edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        for(int i=0 ; i<n ; i++){
            int sz = bfs(i,adj,n,dt);
            if(sz<=mn_size){
                mn_size = sz;
                res = max(res,i);
            }
        }

        return res;
    }

    int bfs(int src,vector<vector<pii>>&adj,int n,int dt){
        vector<int> dist(n,INT_MAX); dist[src]=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second; pq.pop();
            for(auto&nbr:adj[node]){
                int nbrNode=nbr.first, nbrDist=nbr.second;
                if(dist[nbrNode]>dist[node]+nbrDist){
                    dist[nbrNode]=dist[node]+nbrDist;
                    pq.push({dist[nbrNode],nbrNode});
                }
            }
        }

        int sz=0;
        for(int d:dist){if(d<=dt){sz++;}}
        return sz;
    }
};