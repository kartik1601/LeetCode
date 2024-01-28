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
                for(int c1=0; c1<cols ; c1++){
                    for(int c2=c1 ; c2<cols ; c2++){
                        int t1 = r1>0 ? prefix[r1-1][c2] : 0;
                        int t2 = c1>0 ? prefix[r2][c1-1] : 0;
                        int t3 = min(r1,c1)>0 ? prefix[r1-1][c1-1] : 0;
                        int sum=prefix[r2][c2]-t1-t2+t3;
                        if(sum==target){res++;}
                    }
                }
            }
        }
        return res;
    }
};