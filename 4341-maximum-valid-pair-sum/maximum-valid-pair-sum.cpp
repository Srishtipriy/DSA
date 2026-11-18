class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size(), pmx = 0, res = 0;

        for (int j = k; j < n; j++) {
            pmx = max(pmx, nums[j - k]);
            res = max(res, pmx + nums[j]);
        }

        return res;
    }
};