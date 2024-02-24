class Solution {
    using pii = pair<int,int>;
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> adj(n);
        for(auto&meeting:meetings){
            adj[meeting[0]].push_back({meeting[1],meeting[2]});
            adj[meeting[1]].push_back({meeting[0],meeting[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        set<int> vis;
        
        while(!pq.empty()){
            pii tp = pq.top(); pq.pop();
            int time=tp.first, person = tp.second;
            if(vis.find(person)!=vis.end()){continue;}
            vis.insert(person);
            for(auto&nbr:adj[person]){
                if(vis.find(nbr.first)==vis.end() && nbr.second>=time){
                    pq.push({nbr.second,nbr.first});
                }
            }
        }
        
        vector<int> res;
        for(int x:vis){res.push_back(x);}
        return res;
    }
};