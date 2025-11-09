class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(auto x: nums){
            map[x]++;
        }

        for(auto x: map){
            if(x.second == 1){
                return x.first;
            }
        }        
        return -1;
    }
};