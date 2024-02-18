class Solution {
    using pll = pair<long long,long long>;
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        vector<int> rooms(n,0);
        
        priority_queue<pll,vector<pll>,greater<pll>> used;
        priority_queue<int,vector<int>,greater<int>> notUsed;
        for(int i=0 ; i<n ; i++){notUsed.push(i);}
        sort(meetings.begin(),meetings.end());
        
        for(int i=0; i<m; i++){
            int st=meetings[i][0], end=meetings[i][1];
            
            while(!used.empty() && used.top().first<=st){
                auto [e,i] = used.top(); used.pop();
                notUsed.push(i);
            }
            if(!notUsed.empty()){
                int tp=notUsed.top(); notUsed.pop();
                used.push({end,tp});
                rooms[tp]++;
            } else {
                // updating predictable next empty room for this meeting
                auto [t,rno] = used.top(); used.pop();
                used.push({t+end-st,rno}); // current meeting end + next meeting's time diff
                rooms[rno]++;
            }
        }
        
        int mx=0, idx=0;
        for(int i=0 ; i<n ; i++){
            if(rooms[i]>mx){mx=rooms[i]; idx=i;}
        }
        return idx;
    }
};