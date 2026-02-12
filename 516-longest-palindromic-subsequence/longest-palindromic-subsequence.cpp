class Solution {
public:
    int solve(string& tx1 , string& tx2 , int i, int j, vector<vector<int>>& dp){
        
        if(i == tx1.size())
            return 0;
        if(j == tx2.size())
            return 0;
        int ans;
        //dp
        if(dp[i][j] != -1){
            return dp[i][j];}
        
        if(tx1[i]== tx2[j]){
            ans = 1 + solve(tx1, tx2, i+1, j+1, dp);
        }
        else{
            ans = max( solve(tx1, tx2, i , j+1, dp ),   solve(tx1, tx2, i+1, j , dp )) ;
        }
        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string a = s;
        reverse( a.begin(), a.end());
        vector<vector<int>> dp(n+1 , vector<int>(n, -1));
        return solve( s, a, 0, 0, dp );
    }
};