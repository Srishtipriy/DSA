class Solution {
private:
    static inline bool isVowel(char& ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        const int n = word.length();
        int res = 0;
        for(int i = 0; i < n; ++i){
            int mask = 0;
            for(int j = i; j < n && isVowel(word[j]); ++j){
                mask |= (1 << (word[j] - 'a'));
                if(__builtin_popcount(mask) == 5) ++res;
            }
        }
        return res;
    }
};