class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        string result="";

        int i = 0;
        while(i < first.size() && i < last.size())  //Compare first and last strings flight & flower
        {
            if(first[i] == last[i])
            {
                result += first[i];
                i++;
            }
            else{
                break;
            }
        }
        return result;
    }
};