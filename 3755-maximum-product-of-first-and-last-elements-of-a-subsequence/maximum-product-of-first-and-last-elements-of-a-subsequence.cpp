// A large positive × large positive = large positive.
// A large negative × large negative = large positive.
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long ma = nums[0];     //Maximum element encountered so far
        long long mi = nums[0];     //min ele..
        long long res= 1LL * nums[0] * nums[m-1];  //0 based indexing so m-1 ->prdt of 1st and lst ele

        for(int i = m ; i<n; i++){
            ma = fmax(ma, nums[i-m+1]);
            mi = fmin(mi, nums[i-m+1]);

            res = max({res, mi * nums[i], ma * nums[i]});  // Maximum product found so far
        }
        return res;
    }
};