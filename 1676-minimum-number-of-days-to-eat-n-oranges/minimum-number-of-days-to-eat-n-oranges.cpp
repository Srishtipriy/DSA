class Solution {
public:
    unordered_map<int, int> dp;

    int minDays(int n) {
        if (n <= 1) 
            return n;

        if (dp.count(n)) 
            return dp[n];

        // Option 1: Make n divisible by 2
        int opt2 = (n % 2) + 1 + minDays(n / 2);        

        // Option 2: Make n divisible by 3
        int opt3 = (n % 3) + 1 + minDays(n / 3);

        return dp[n] = min(opt2, opt3);
    }
};
