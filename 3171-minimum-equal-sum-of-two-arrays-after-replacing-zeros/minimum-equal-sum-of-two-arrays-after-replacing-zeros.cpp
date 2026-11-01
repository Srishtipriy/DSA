class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1 = 0;
        int z2 = 0;
        long long s1=0 , s2=0;

        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]==0)
                z1++;
            s1+=nums1[i];
        }
        s1 += z1;

        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==0)  
                z2++;
            s2 +=nums2[i];
        }
        s2 += z2;
        
        if((s1<s2 && z1==0) || (s2<s1 && z2==0)) return -1;

        return max(s1,s2);

    }
};