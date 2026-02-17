class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int sum = start ^ goal;         //diff no pe 1 mil gaya --> same pe 0

        while (sum){
            sum = sum & (sum-1);
            count++;
        }
    return count;
    }
};