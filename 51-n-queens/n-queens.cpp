class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col) {
        for(int i=row-1; i>=0; i--) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=row-1,j=col+1; i>=0 && j<board.size(); i--,j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<vector<char>>& board,int row,vector<vector<string>>& ans) {
        if(row == board.size()) {
            printqu(board ,ans);
            return;
        }
        for(int j=0; j<board[0].size(); j++) {
            if(issafe(board,row,j)) {
                board[row][j] = 'Q';
                nQueens(board,row+1,ans);
                board[row][j] = '.';
            }
        }
    }
    void printqu(vector<vector<char>>& board,vector<vector<string>>& ans) {
        vector<string> temp;
        for(int i=0; i<board.size(); i++) {
            string row = "";
            for(int j=0; j<board[0].size(); j++) {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = '.';
            }
        }
        nQueens(board,0,ans);
        return ans;
    }
};