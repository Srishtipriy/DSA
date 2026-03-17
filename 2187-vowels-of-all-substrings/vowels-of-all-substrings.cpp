class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    
    long long countVowels(string word) {
        long long count = 0;
        int len = word.size();
        
        for(int i = 0; i < len; i++) {
            if(isVowel(word[i])) {
                count += (long)(len - i) * (long)(i + 1);
            }
        }
        
        return count;
    }
};