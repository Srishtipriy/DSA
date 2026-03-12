class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<int> maxhp;

        for(int r =0; r<m; r++){
            for(int c =0;c<n; c++){
                maxhp.push(matrix[r][c]);
                if(maxhp.size() > k){
                    maxhp.pop();
                }
            }
        }
        return maxhp.top();
    }
};