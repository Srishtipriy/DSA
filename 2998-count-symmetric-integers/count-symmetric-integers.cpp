class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;

        for (int r = low; r <= high; r++) {
            string digi = to_string(r);
            
            if (digi.size() % 2 != 0)    continue;      // Odd number of digits
            int f = digi.size() / 2;

            int sum = 0, sum2 = 0;

            for (int i = 0; i < f; i++) {               // First half
                sum += digi[i] - '0';
            }
            
            for (int i = f; i < digi.size(); i++) {     // Second half
                sum2 += digi[i] - '0';
            }
            if (sum == sum2)
                res++;
        }
        return res;
    }
};