class Solution {
public:
    bool checkValidString(string s) {
         int low = 0, high = 0;
         for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else if (c == '*') {
                low--;     // treat '*' as ')'
                high++;    // or '('
            }

            if (high < 0) return false; // too many ')'
            if (low < 0) low = 0;       // can't go below 0
        }

        return low == 0;
    }
};