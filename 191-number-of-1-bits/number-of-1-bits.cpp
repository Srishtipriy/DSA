class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while(n){           //runs onl as many times as 1 present in binary no "n"
            n = n & (n-1);
            count++;
        }

        return count;
    }
};