class Solution {
public:
    int solve(string& tx1 , string& tx2 , int i, int j, vector<vector<int>>& dp){
        if(i == tx1.size())
            return 0;
        if(j == tx2.size())
            return 0;
        int ans = 0;
        //dp
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(tx1[i]== tx2[j]){
            ans = 1 + solve(tx1, tx2, i+1, j+1, dp);
        }
        else{
            ans = max( solve(tx1, tx2, i , j+1, dp ),   solve(tx1, tx2, i+1, j , dp)) ;
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n+1 ,vector<int> (m, -1));
        return solve(text1, text2 , 0, 0, dp);
    }
};