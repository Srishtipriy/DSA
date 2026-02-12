class Solution {
public:
    int solve(int index, int k, int operationNo, vector<int>& prices, vector<vector<int>>& dp) {
        
        if(index == prices.size())
            return 0;
        if(operationNo == 2*k)     // 2 buy and 2 sell
            return 0;
        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int profit = 0;

        if( operationNo %2 == 0) {
            int buyKaro = -prices[index] + solve(index + 1, k , operationNo+1 , prices, dp);
            int skipKaro = 0 + solve(index + 1, k, operationNo, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[index] + solve(index + 1, k, operationNo+1 , prices, dp);
            int skipKaro = 0 + solve(index + 1, k , operationNo , prices, dp );
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][operationNo] = profit;
    }

    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2*k , -1));
        return solve(0, k, 0, prices, dp);
    }
};
