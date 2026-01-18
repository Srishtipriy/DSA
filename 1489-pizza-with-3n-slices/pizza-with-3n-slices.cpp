class Solution {
public:
     int solveTab(int st,int l,vector<int>& slices,int k){
        int n = l-st;
        vector<vector<int>> dp(n+2,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j = 1;j<=k;j++){
                int inc = slices[st+i] + dp[i+2][j-1];
                int exc = dp[i+1][j];
                dp[i][j] = max(inc,exc);
            }
        }
        return dp[0][k];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        int case1 = solveTab( 0, n-1, slices, n/3 );
        int case2 = solveTab( 1, n,   slices, n/3 ); 
        return max(case1,case2);
    }
};