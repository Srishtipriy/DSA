class Solution {
public:
    int solve(vector<int>& cost, int n) {
        vector<int> dp(n+1);                             //step 1 
        int prev2 = cost[0];                             //step 2-- base cases ko dp m likho
        int prev1 = cost[1];
        
        for(int i =2 ;i<n ; i++){
            int curr = cost[i] +min(prev1 , prev2); 
            prev2 = prev1;
            prev1 = curr;                    // recusrion wala format dp m likh do
        }
    return min(prev2, prev1);               // this line from main fun jaha ans ko call kar arhe the
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        return solve(cost, n);     // Tum 0 ya 1 step se start kar sakte ho
    }
};