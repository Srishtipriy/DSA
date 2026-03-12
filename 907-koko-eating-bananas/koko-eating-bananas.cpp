class Solution {
public:
    int f(vector<int>& piles, int h) {
        int hours = 0;

        for (int i = 0; i < piles.size(); i++){
            hours += piles[i] / h;
            if (piles[i] % h > 0)
                hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1000000001;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (f(piles, mid) <= h) {
                r = mid;
            } 
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};