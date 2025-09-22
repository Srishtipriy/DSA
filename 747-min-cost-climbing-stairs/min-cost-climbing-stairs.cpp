class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int> & dp) {
        if (i >= cost.size()) return 0;   // Top par pahunch gaye
        
        if(dp[i] != -1)  return dp[i];

        int one = cost[i] + solve(cost, i+1, dp);       // Ek step aur do step dono try karo
        int two = cost[i] + solve(cost, i+2, dp);

        dp[i] =min(one, two);
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp (n+1, -1);
        int ans =min(solve(cost, 0 ,dp), solve(cost, 1,dp));     // Tum 0 ya 1 step se start kar sakte ho
        return ans;
    }
};