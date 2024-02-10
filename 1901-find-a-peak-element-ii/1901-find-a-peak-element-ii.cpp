class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int t=i>0 ? mat[i-1][j]:-1, b=i<n-1 ? mat[i+1][j]:-1;
                int l=j>0 ? mat[i][j-1]:-1, r=j<m-1 ? mat[i][j+1]:-1;
                
                if(mat[i][j]>t && mat[i][j]>b && mat[i][j]>l && mat[i][j]>r){
                    return {i,j};
                }
            }
        }
        
        return {};
    }
};