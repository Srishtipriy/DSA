class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int n= s.length();
        int maxLen = 0;
        int L = 0;

        for(int R =0 ; R<n ;R++){
            while( window.find( s[R] ) != window.end() ) {
                window.erase( s[L] );
                L++;
            }
            
        window.insert( s[R] );
        maxLen = max( maxLen, R - L +1 );
            
        }
        return maxLen;
    }
};