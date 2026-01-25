class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int ans = 2;
        vector<unordered_map<int, int>> dp(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                else 
                    cnt = 1;

                dp[i][diff] = max(dp[i][diff], cnt + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
