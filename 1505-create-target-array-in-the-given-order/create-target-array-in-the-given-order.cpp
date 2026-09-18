class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target(nums.size(), 0);
        int n = nums.size(),
            currSize = 0;
        
        for (int i = 0; i < n; i++) {
            int pos = index[i],
                val = nums[i];
            
            for (int j = currSize; j > pos; j--) {
                target[j] = target[j - 1];
            }
           
            target[pos] = val;
            currSize++;
        }
        
        return target;
    }
};