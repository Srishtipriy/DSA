class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        string binary= "";
        // if(n== 0)   return {0};

        for(int i = 0; i<=n ; i++){
            if(n == 0)   return {0};
            int I = i;
            int count = 0;
            while (I > 0) {
                int bit = I % 2;           // remainder (0 or 1)
                count += bit;
                I /= 2;                    // divide by 2
            }
            ans.push_back(count);
        }
    return ans;
    }
};