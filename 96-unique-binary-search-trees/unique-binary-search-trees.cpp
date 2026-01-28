class Solution {
public:
    int solve(int n, vector<int>& dp ){
        if(n == 0 || n == 1)
            return 1;
        int ans = 0;

        if(dp[n] != -1)
            return dp[n];

        //think i as root ele
        for(int i= 1; i<=n ; i++){
            ans += solve(i-1 , dp) * solve(n-i , dp);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n, dp);
    }
};