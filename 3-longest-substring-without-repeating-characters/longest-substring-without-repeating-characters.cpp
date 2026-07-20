class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int maxlen = 0;
        int l = 0;

        for(int r=0; r<s.size() ; r++){
            while(set.find(s[r]) != set.end() ){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};