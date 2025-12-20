class Solution {
public:
    int solvemem( vector<int>&satisfaction, int index, int time, vector<vector<int>>& dp){
        int n = satisfaction.size();
        if(index == n ){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include = satisfaction[index]*(time + 1) + solvemem(satisfaction, index+1, time+1, dp);
        int exclude = 0 + solvemem(satisfaction, index+1 , time , dp);

        dp[index][time] = max(include , exclude);
        return dp[index][time];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n= satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solvemem(satisfaction , 0, 0 , dp);
    }
};