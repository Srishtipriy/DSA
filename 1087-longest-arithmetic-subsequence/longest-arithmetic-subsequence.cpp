class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        int ans = 2;

        vector<unordered_map<int,int>> dp(n);

        for(int i=1; i<n; i++ ){
            for(int j=0; j<i; j++ ){
                int diff= nums[i]-nums[j];
                int len = dp[j].count(diff) ?  dp[j][diff]+1  : 2;

                dp[i][diff] = max(dp[i][diff] , len);
                ans = max(dp[i][diff] , ans);
            
            }
        }
        return ans;
    }
};