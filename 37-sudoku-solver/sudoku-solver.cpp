class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {       //char it ho raha h
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num;
                            if (solve(board)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false; //1se9 if statmnt m yek it. 1 ya 2 ya3 ki fail hogai new se start kro
                }
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {        // sidhhi row and col check
                return false;
            }
        }
        int startRow = (row / 3) * 3;           //(0 indexed hai) so (4,7) 6th block ke mid val denote hoti h 
        int startCol = (col / 3) * 3;           //trick to get top left of 6th block (3,6) total 8 row & colh
        for (int i = startRow; i < startRow + 3; i++) {         // 3 4 5 loop
            for (int j = startCol; j < startCol + 3; j++) {     // 6 7 8 loop
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
};