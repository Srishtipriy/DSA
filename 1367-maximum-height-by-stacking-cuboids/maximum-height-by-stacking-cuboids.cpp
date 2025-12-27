class Solution {
public:
    int solve(int n, vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp) {
        if (curr == n) return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0;
        if (prev == -1 ||
            (cuboids[prev][0] <= cuboids[curr][0] &&
             cuboids[prev][1] <= cuboids[curr][1] &&
             cuboids[prev][2] <= cuboids[curr][2])) {

            take = cuboids[curr][2] +
                   solve(n, cuboids, curr + 1, curr, dp);
        }

        int nottake = solve(n, cuboids, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());   // sort dimensions

        sort(cuboids.begin(), cuboids.end()); // sort cuboids

        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(n, cuboids, 0, -1, dp);
    }
};
