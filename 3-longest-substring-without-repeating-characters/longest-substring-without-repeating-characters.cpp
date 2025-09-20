class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int n= s.size();
        int maxLen = 0;
        int R = 0;
        int L = 0;

        while(R < n){
            if( window.find( s[R] ) == window.end() ){
                window.insert( s[R] );
                maxLen = max( maxLen, R - L +1 );
                R++;
            }
            else{
                window.erase( s[L] );
                L++;
            }
        }
        return maxLen;
    }
};