class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int rows=mat.size(), cols=mat[0].size();
        vector<vector<int>> prefix(rows,vector<int>(cols,0));
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                int t = i>0 ? prefix[i-1][j] : 0;
                int l = j>0 ? prefix[i][j-1] : 0;
                int tl = min(i,j)>0 ? prefix[i-1][j-1] : 0;
                prefix[i][j] = mat[i][j]+t+l-tl;
            }
        }
        
        int res=0;
        for(int r1=0; r1<rows ; r1++){
            for(int r2=r1; r2<rows ; r2++){
                unordered_map<int,int> mp;
                mp[0]=1;
                for(int c=0; c<cols ; c++){
                    int top = r1>0 ? prefix[r1-1][c] : 0;
                    int curr_sum = prefix[r2][c]-top;
                    if(mp.find(curr_sum-target)!=mp.end()){res+=mp[curr_sum-target];}
                    mp[curr_sum]++;
                }
            }
        }
        return res;
    }
};