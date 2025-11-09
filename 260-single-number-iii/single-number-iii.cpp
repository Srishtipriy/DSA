class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;
        
        for(auto x: nums){
            map[x]++;               // all values in map stored
        }

        for(auto x: map){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }        
        return ans;
    }
};                                                                                                              