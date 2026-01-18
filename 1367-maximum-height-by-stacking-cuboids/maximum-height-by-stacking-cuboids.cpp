class Solution {
public:
    bool check(vector<int> base, vector<int> NewBox){
        if( NewBox[0]<= base[0] && NewBox[1]<= base[1] && NewBox[2]<= base[2]){
            return true;
        }
        else 
            return false;
            
    }
    int solve(int n, vector<vector<int>>& a, int curr, int prev, vector<vector<int>>& dp) {
        if (curr == n) return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0;
        if (prev == -1 || check( a[curr] , a[prev]) ) {

            take = a[curr][2] +solve(n, a, curr + 1, curr, dp);
        }

        int nottake = solve(n, a, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());      // sort dimensions

        sort(cuboids.begin(), cuboids.end()); // sort cuboids

        int n = cuboids.size();                     
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));      //dp

        return solve(n, cuboids, 0, -1, dp);
    }
};
