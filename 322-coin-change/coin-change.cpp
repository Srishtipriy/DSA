class Solution {
public:
    int solve(vector<int>& coins, int amt, vector<int>& dp ){
        //base case
        if( amt<0)     return INT_MAX;                         //step 2

        if(amt== 0)        return 0;

        int mini = INT_MAX;
        if (dp[amt] != -1)       return dp[amt];              //step 3

        for(int c : coins){
            int ans = solve (coins , amt-c  , dp);
            if(ans!= INT_MAX){
                mini = min(mini, 1+ans);                //kyuki humne start of RC m hi yek coin use kar liya tha
            }
        }
        return dp[amt] = mini;

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;

    }
};
