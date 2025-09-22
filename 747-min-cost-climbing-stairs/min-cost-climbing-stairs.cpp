class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if(n ==1)     return cost[1];                                      //base cases

        if(n ==0)      return  cost[0];
        
        if (dp[n] != -1 ){                                          //dp addition step 3
            return dp[n];
        }
        dp[n] = cost[n] + min( solve(cost, n-1, dp), solve(cost, n-2 ,dp ) );           //step 2
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int> dp(n+1 , -1);
        int ans = min( solve(cost, n-1 ,dp), solve(cost, n-2, dp) );
        return ans;     // Tum 0 ya 1 step se start kar sakte ho
    }
};
