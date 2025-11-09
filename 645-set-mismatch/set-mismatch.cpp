class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {      //1 2 2 4
    int N= nums.size();
    sort(nums.begin(),nums.end());
    vector<int> ans;
    int duplicate= -1;
    int missing = 1;

    for (int i = 1; i < N; i++) {
        if(nums[i]== nums[i-1]) {
            duplicate = nums[i];
        }
        else if(nums[i]> nums[i-1]+ 1){ //dupli no phele wla +1 ==> 4 > (2 + 1) → 4 > 3 ✅ true
            missing = nums[i-1]+ 1;
        }
    }
    if(nums[N-1] != N){         // jab missin no last no. ho like 1 2 2 3 ==> size is 4 missing = 4
         missing =N;
     }
    ans.push_back(duplicate);
    ans.push_back(missing);

    return ans;
    }
};