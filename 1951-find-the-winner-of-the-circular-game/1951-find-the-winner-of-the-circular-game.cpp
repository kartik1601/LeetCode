class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> f(n);
        for(int i=0 ; i<n ; i++){f[i]=i+1;}

        int curr=0;
        while(f.size()>1){
            int loser = (curr+k-1)%f.size();
            f.erase(f.begin() + loser);
            curr = loser;
        }
        return f[0];
    }
};