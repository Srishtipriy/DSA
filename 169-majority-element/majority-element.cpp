class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());      //Once the array is sorted, the majority element will always be                                             present at index n/2, where n is the size of the array.
        int n = nums.size();
        return nums[n/2];
    }
};