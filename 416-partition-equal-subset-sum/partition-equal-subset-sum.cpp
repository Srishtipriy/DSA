class Solution {
public:
    bool solveMem( int index, vector<int> &arr , int n, int target ,vector<vector<int>>& dp){

        if(index >= n)
            return 0;
        if(target < 0)              //target minus karte karte negative ho gaya 
            return 0;
        if(target == 0)
            return 1;
        if(dp[index][target] != -1)
            return dp[index][target];

        int incl = solveMem(index+1 ,arr ,n ,target- arr[index] ,dp);
        int excl = solveMem(index+1 ,arr ,n ,target ,dp);

        dp[index][target] = (incl or excl);
        return dp[index][target];

    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i=0; i<n ;i++){
            sum += nums[i] ;
        }
        if( sum & 1) return false; //sare no odd ho

        if( sum%2 != 0 ) return false;  //sum ka half ho sake woh even val na ho

        int target = sum/2;
        vector<vector<int>> dp(n+1 , vector<int>(target+ 1, -1));

        return solveMem( 0 ,nums, n, target, dp);   

    }
};