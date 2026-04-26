class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();    
        set<int>st;
        for(auto it: nums){
            st.insert(it);
        }

        int q = st.size();
        int count = 0;
        for(int i  =0 ;i<n ;i++){
            set<int>p;
            for(int j =i ;j<n ;j++){
                p.insert(nums[j]);
                if(p.size() == q)      count++;
            
            }
        }
        return count;
    }
};