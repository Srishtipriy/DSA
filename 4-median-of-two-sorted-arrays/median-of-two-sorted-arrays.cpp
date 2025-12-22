class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();

        vector<int> merged;
        for(int i=0; i<n; i++)
            merged.push_back(nums1[i]);

        for(int j=0; j<m; j++)
            merged.push_back(nums2[j]);

        sort(merged.begin(), merged.end());

        int total = merged.size();

        if(total % 2 == 1 ){
            int mid = merged[total / 2];
            return mid;
        }
        else{
            double mid1 = merged[total / 2 - 1];
            double mid2 = merged[total / 2 ];
            double actual = (mid1+mid2)/2 ;
            return actual;
        }
    }
};