class Solution {
public:
    int solve(int n, vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev +1] != -1){      //prev+1 kiya gaya becoz woh (-1se n-1) ja raha tha valid krne ke liye
            return dp[curr][prev+1];
        }

        //include
        int take = 0;
        if(prev == -1 || nums[prev]< nums[curr] ){
            take = 1 + solve(n, nums, curr+1, curr, dp);
        }
        //exclude
        int nottake = solve(n, nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(take, nottake);
    }
    
    int solveTab(int n, vector<int>& nums){
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
        for(int curr  = n-1; curr >= 0; curr --){
            for(int prev= curr-1; prev>= -1; prev--){

                int take = 0;
                if(prev == -1 || nums[prev] < nums[curr] ){
                    take = 1+ dp[curr+1][curr +1];
                }
                int notake = 0 + dp[curr+1] [prev+1];

                dp[curr][prev +1] = max(take , notake);
            }
        }
        return dp[0][0];

    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve (n, nums, 0, -1, dp);

        return solveTab(n, nums);

    }
};