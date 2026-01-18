class Solution {
public:
    int getMaxPizza(int startPoint, int endPoint, vector<int>& slices, int remSlice, vector<vector<int>> &dp){

        if(remSlice == 0 || startPoint > endPoint){
            return 0;
        }

        if( dp[startPoint][remSlice] != -1 ){
            return dp[startPoint][remSlice];
        }

        int eat_Pizza  = slices[startPoint] +  getMaxPizza(startPoint+2, endPoint, slices, remSlice - 1, dp);
        int skip_Pizza = 0 + getMaxPizza(startPoint+1, endPoint, slices, remSlice, dp);

        dp[startPoint][remSlice] = max(eat_Pizza, skip_Pizza);
        
        return dp[startPoint][remSlice];

    }

    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();
        int n = k/3;

        vector<vector<int>> dp1(k, vector<int>(n+1, -1));
        vector<vector<int>> dp2(k, vector<int>(n+1, -1));

        int max_start = getMaxPizza(0, k - 2, slices, n, dp1);
        int max_end   = getMaxPizza(1, k - 1, slices, n, dp2);


        return max(max_start, max_end);

    }
};