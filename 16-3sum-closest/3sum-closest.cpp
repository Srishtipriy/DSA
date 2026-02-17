class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = nums[0] + nums[1] + nums[2];      //1st sum

        for(int i= 0; i<nums.size()-2 ; i++){           //last 2 nahi iterate hoga
            int l = i +1;
            int r = n-1;

            while(l< r){
                int sum = nums[i] + nums[l] + nums[r];

                if(abs(target - sum) < abs(target - res))       //jab tar-sum kam ho res se
                    res = sum;

                if(sum == target)
                    return target;
                else if(sum < target) l++;
                else r--;
            }
        }
        return res;
    }
};