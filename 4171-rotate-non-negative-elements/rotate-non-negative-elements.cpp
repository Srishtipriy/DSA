class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> positive;

         for(int i=0; i<n; i++){                //positive ka array
            if( nums[i] >= 0 ){
                positive.push_back(nums[i]);
            }
         }
        int m = positive.size();
        if(m == 0)  return nums;
        k= k % m;

        vector<int> rotated;                //positive rotated array
        for(int j= 0; j<m; j++){
            int a = positive[ (j+k) % m ];
            rotated.push_back(a);
        }

        int idx= 0;                         //full ans array
        for(int i=0; i<n; i++){
            if(nums[i] >= 0 )
                nums[i] = rotated[idx++];       
        } 
        return nums;
    }
};