class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() ;
        int left = 0 ;
        int lsum = 0, rsum = 0 ;
        while (left < k) {
            lsum += cardPoints[left++] ;
        }
        int maxx = lsum ;
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k-1-i] ;
            rsum += cardPoints[n-i-1] ;
            maxx = max(maxx, lsum + rsum) ;
        }
        return maxx ;
    }
};






 // Time Complexity: O(2*k) & Space Complexity: O(1)