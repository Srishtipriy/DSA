#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int pair = 0;

        while (left < right) {
            int total = nums[left] + nums[right];

            if (total < target) {
                pair += (right - left);
                left++;
            } else {
                right--;
            }
        }

        return pair;
    }
};