class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        
        if (n <= 0)
            return false; 
        
        // Calculate the logarithm of 'n' with base 4
        double logarithmBase4 = log(n) / log(4);
        
        // Check if the result of the logarithmic operation is an integer
        return (logarithmBase4 == (int)logarithmBase4);
    }
};