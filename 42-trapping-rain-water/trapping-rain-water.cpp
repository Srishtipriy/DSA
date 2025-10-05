class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0; 
        int i=0, j=1;
        int ans = 0;
        int sum = 0;
        while(j<n){
            if(height[j]>=height[i]){
                ans += (j-i-1)*(height[i]) - sum;
                i=j;
                j++;
                sum = 0;
                continue;
            }
            sum += height[j];
            j++;
        }
        int k = n - 1;
        j = n - 2;
        sum = 0;
        while (j >= i) {
            if (height[j] >= height[k]) {
                ans += (k - j - 1) * height[k] - sum;
                k = j;
                j--;
                sum = 0;
                continue;
            }
            sum += height[j];
            j--;
        }

        return ans;
    }
};