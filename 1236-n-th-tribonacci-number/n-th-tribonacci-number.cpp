class Solution {
public:
    int fibo(int n, vector<int>& dp){

        if(n<= 1)   return n;
        if(n==2)   return 1;

        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = fibo(n-1,dp) + fibo(n-2,dp) + fibo(n-3,dp);
        return dp[n];

    }
    int tribonacci(int n) {
        vector<int> dp(n+1);

        for(int i=0; i<=n ; i++){
            dp[i]=-1;
        }
        int f= fibo(n,dp);
        return f;
    }
};