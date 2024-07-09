class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        double wait=0, clock=0;
        for(int i=0 ; i<n ; i++){
            if(c[i][0]>clock){clock=c[i][0];}
            clock += c[i][1];
            wait += clock-c[i][0];
        }
        return double(wait/n);
    }
};