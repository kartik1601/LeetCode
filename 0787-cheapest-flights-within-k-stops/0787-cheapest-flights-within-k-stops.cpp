class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto f : flights){
            graph[f[0]].push_back({f[1],f[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> minDist(n,INT_MAX);

        while(!q.empty()){
            auto top = q.front(); q.pop();
            int stops=top.first, node=top.second.first, cost=top.second.second;
            if(stops > k)   continue;
            for(auto adj : graph[node]){
                int adjNode=adj.first , adjW=adj.second;
                if(cost+adjW < minDist[adjNode] && stops <= k){
                    minDist[adjNode] = cost + adjW;
                    q.push({stops+1,{adjNode,cost+adjW}});
                }
            }
        }

        return minDist[dst]==INT_MAX ? -1 : minDist[dst];
    }
};