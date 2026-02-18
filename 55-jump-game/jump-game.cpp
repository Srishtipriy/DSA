class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;

        for(int i=0; i<nums.size(); i++){
            if(i > maxreach)          // If the current index is beyond our furthest reachable index,  
                return false;
            maxreach = max(maxreach,  i+ nums[i]);
        }
        return true;
    }
};