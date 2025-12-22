class Solution {        //binary search = optimal approach
public:
    int binarysearch(int n, vector<int>& nums){
        if(n == 0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i =1; i<n; i++){
            if( nums[i] > ans.back() ){
                ans.push_back(nums[i]);
            }
            else{
                //findin the index of jusst bada ele in ans
                int index = lower_bound(ans.begin(), ans.end() , nums[i] ) - ans.begin(); 
                //address de dega - ans.begin() se;
                ans[index] = nums[i];
            }
        }
        return ans.size();

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return binarysearch(n , nums);
    }
};