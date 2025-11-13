class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        
        // Initialize currSum and maxSum to the sum of the initial k elements
        for (int i = 0; i < k; i++){
            currSum += nums[i];
        }
        maxSum = currSum;
        
        // Start the loop from kth ele ->Iterate until you reach the end
        for (int i = k; i < nums.size(); i++) {
            // Subtract the left ele of window ->Add the right ele of window
            currSum += nums[i] - nums[i - k];
                
            maxSum = max(maxSum, currSum);      // Update the max
        }
        
        // Since the problm req average, we return the avg
        return maxSum / k;
    }
};