class Solution {
public:
    bool frogjump(int idx, int lastJump, vector<int>& stones, vector<vector<int>>& dp) {
        int n = stones.size();                  
        if (idx == n-1) return true;                //basecase

        if (dp[idx][lastJump] != -1) 
            return dp[idx][lastJump];

        for (int next = idx + 1; next < n; next++) {
            int gap = stones[next] - stones[idx];
            if (gap < lastJump - 1) continue;   // too small
            if (gap > lastJump + 1) break;      // too large (stones sorted)

            if (frogjump(next, gap, stones, dp))
                return dp[idx][lastJump] = true;
        }

        return dp[idx][lastJump] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
                             
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return frogjump(0, 0, stones, dp);
    }
};
