class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int index = 0;
        
        for(int num : nums){
            if(seen.find(num) == seen.end()){           //agar woh no nahi mila seen.end() is a end pointer jo last ele ke bhi baad mai point krta ho
            
                seen.insert(num);
                nums[index] = num;
                index++;

            }
        }
        return index;
    }
};