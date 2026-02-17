class Solution {
public:
    int solve(vector<int> & height){
        int n = height.size();
        int l =0, r = n-1;
        int area = 0, maxArea = INT_MIN;

        while( l < r ){
                int h = min(height[l] , height[r]);

                area = h * (r - l);
                maxArea = max(area, maxArea); 

                if(height[l] < height[r])
                    l++;
                else 
                    r--;     
        }
        return maxArea;
    }
    int maxArea(vector<int>& height) {
        return solve(height);
    }
};