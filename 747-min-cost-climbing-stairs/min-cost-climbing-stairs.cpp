class Solution {
public:
    int solve(vector<int>& cost, int n) {
        vector<int> dp(n+1);                             //step 1 
        dp[0] = cost[0];                                 //step 2-- base cases ko dp m likho
        dp[1] = cost[1];
        
        for(int i =2 ;i<n ; i++){
            dp[i] = cost[i] +min(dp[i-1] , dp[i-2]);            // recusrion wala format dp m likh do
        }
    return min(dp[n-1], dp[n-2]);               // this line from main fun jaha ans ko call kar arhe the
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        return solve(cost, n);     // Tum 0 ya 1 step se start kar sakte ho
    }
};