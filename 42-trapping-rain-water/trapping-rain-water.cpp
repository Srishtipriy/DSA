class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        long long ans = 0;
        int l= 0 , r=n-1;
        int lmax = 0 , rmax = 0;

        while(l<r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);

            if(lmax < rmax){                //boundary is Left
                ans += lmax - height[l];   //lmax hamesa largest val store karega so mini ans m 0 store hoga.
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};