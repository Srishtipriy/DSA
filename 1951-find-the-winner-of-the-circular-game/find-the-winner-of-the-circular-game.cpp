class Solution {
public:
    int solve(int n, int k){
        //base case
        if(n==1)
        return 0;

        //recursive call
        return (solve( n-1, k ) + k )% n;       // +k Rcall mai k times chalane kokiya gaya h & %n due toin ar rah
                                            
    }
    int findTheWinner(int n, int k) {
        int ans= solve(n , k) +1;       //O-based indexing ki wajah se +1 kiya gaya h
        return ans;
    }
};