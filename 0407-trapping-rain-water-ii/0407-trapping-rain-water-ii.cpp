#define t vector<int>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m=h.size(), n=h[0].size();

        priority_queue<t,vector<t>,greater<t>> pq;
        vector<t> vis(m,t(n,0));

        for(int i=0 ; i<n ; i++){
            vis[0][i]=1; vis[m-1][i]=1;
            pq.push({h[0][i],0,i});
            pq.push({h[m-1][i],m-1,i});
        }
        for(int i=1 ; i<m-1 ; i++){
            vis[i][0]=1; vis[i][n-1]=1;
            pq.push({h[i][0],i,0});
            pq.push({h[i][n-1],i,n-1});
        }

        int res = 0, dirs[5]={1,0,-1,0,1};
        while(!pq.empty()){
            auto v = pq.top(); pq.pop();
            int ht=v[0], x=v[1], y=v[2];

            for(int i=0 ; i<4 ; i++){
                int dx = x + dirs[i], dy = y + dirs[i+1];
                if(dx>=0 && dy>=0 && dx<m && dy<n && !vis[dx][dy]){
                    vis[dx][dy] = 1;
                    if(ht > h[dx][dy]){
                        int diff = ht - h[dx][dy];
                        res += diff;
                        pq.push({ht,dx,dy});
                    } else {
                        pq.push({h[dx][dy],dx,dy});
                    }
                }
            }
        }

        return res;
    }
};