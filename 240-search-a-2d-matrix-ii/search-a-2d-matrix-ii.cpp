class Solution {
public:
    bool solve(vector<vector<int>>& matrix,int target, int n, int m, int i, int j){
        if( i>=n || j < 0 )   return false;

        if(matrix[i][j] == target)  return true;

        if(matrix[i][j] > target)
            return solve(matrix,target, n, m, i, j-1);

        return solve(matrix,target, n, m, i+1, j);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m-1;
        return solve(matrix,target, n, m, i, j);

    }
};