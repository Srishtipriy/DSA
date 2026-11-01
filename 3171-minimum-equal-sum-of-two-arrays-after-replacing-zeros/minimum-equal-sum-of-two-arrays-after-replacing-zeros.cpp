class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1 = count(nums1.begin(), nums1.end(), 0);
        int z2 = count(nums2.begin(), nums2.end(), 0);

        long long s1 =0, s2=0;
        for(int i=0; i<nums1.size() ; i++){
            s1 += nums1[i];
        }
        s1 += z1;
        for(int i=0; i<nums2.size() ; i++){
            s2 += nums2[i];
        }
        s2 += z2;

        if( (s1 <s2 && z1==0 ) || (s2<s1 && z2==0 )){
            return -1;
        }     
        //cout<<s1 <<" "<< s2;   
        return max(s1, s2);
    }
};