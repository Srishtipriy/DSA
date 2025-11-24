class Solution {
public:
    unordered_map<int,int> dp;
    int func(int n){
        //base case
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp.find(n)!=dp.end()) 
            return dp[n];               //n is found in the dp cache
        
       return dp[n]= 1 + min( (n%2) + func(n/2), (n%3) + func(n/3) );
    }
    int minDays(int n) {
        return func(n);
    }
};