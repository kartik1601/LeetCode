class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&adj,vector<string>&res,string port){
        while(!adj[port].empty()){
            string nbr = adj[port].front();
            adj[port].erase(adj[port].begin());
            dfs(adj,res,nbr);
        }
        res.push_back(port);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
    
        for(auto&ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        
        for(auto&p:adj){
            auto &v = p.second;
            sort(v.begin(),v.end());
        }

        vector<string> res;
        dfs(adj,res,"JFK");
        reverse(res.begin(),res.end());

        return res;
    }
};