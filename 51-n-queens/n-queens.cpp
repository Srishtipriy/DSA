class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col,  int n){
        for(int i=0; i<row ; i++){                //Q2 ki row fix h uske upper ki col checking //ya i<=row-1
            if( board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row-1,  j= col-1 ; i>=0 && j>=0 ; i--, j-- ){           // upper-left diagonal
            if(board[i][j]== 'Q'){
                return false;
            }
        }
        for(int i = row-1,  j= col+1 ; i>=0 && j<n ; i--, j++ ){               // upper-right diagonal
            if(board[i][j]== 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board, int row, int n, vector<vector<string>>& ans){
        if(row == n){               //all rows are covered then
            ans.push_back(board);
            return ;
        }
        for(int col= 0 ; col<n ; col++){                  //j here means "col"
            if(isSafe(board , row , col , n )){                   //if true hua toh hi proceed and put "Q"
                board[row][col] = 'Q';
                solve(board, row+1 , n , ans);           //backtrack
                board[row][col] = '.';               
            }
        }     
    }
    vector<vector<string>> solveNQueens(int n) {        //n is input queens
        vector<string> board (n, string( n, '.'));
        vector<vector<string>> ans;
        solve(board, 0, n, ans);
        return ans;
    }
};