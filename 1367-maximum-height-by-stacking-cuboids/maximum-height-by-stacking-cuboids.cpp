class Solution {
public:
    int solve(int curr, int prev, vector<vector<int>>& cuboids, vector<vector<int>>& dp) {
        if (curr == cuboids.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0;
        if (prev == -1 ||
            (cuboids[prev][0] <= cuboids[curr][0] &&
             cuboids[prev][1] <= cuboids[curr][1] &&
             cuboids[prev][2] <= cuboids[curr][2])) {

            take = cuboids[curr][2] +                   //add height not +1
                   solve(curr + 1, curr, cuboids, dp);
        }

        int notTake = solve(curr + 1, prev, cuboids, dp);

        return dp[curr][prev + 1] = max(take, notTake);
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        //sort the inside vector height at last-> sort all dimensions
        for( auto &a : cuboids){
            sort(a.begin(), a.end());
        }
        //now sort all cuboids basis of w and l
        sort(cuboids.begin(), cuboids.end());

        //using LIS solution
        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, cuboids, dp);
    }
};