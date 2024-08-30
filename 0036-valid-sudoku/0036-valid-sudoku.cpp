class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0}, col[9][10]={0}, subgrid[9][10]={0};
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] == '.'){continue;}
                int ch = board[i][j] - '0';
                int subIdx = (i/3)*3 + (j/3);
                if(row[i][ch] || col[j][ch] || subgrid[subIdx][ch]){
                    return false;
                }

                row[i][ch] = col[j][ch] = subgrid[subIdx][ch] = 1;
                
            }
        }

        return true;
    }
};