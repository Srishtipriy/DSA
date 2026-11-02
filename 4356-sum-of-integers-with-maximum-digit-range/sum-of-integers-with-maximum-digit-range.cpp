class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxsum =0;
        int maxrange =-1;

        for(int i=0; i<nums.size(); i++){

            string n = to_string(nums[i]);
            int maxdigit =0;    //Kyuki hume har no. k digits ka mx aur min sepely cal karna h.
            int mindigit =9;

            for(int c= 0; c < n.size() ; c++){
                maxdigit = max(maxdigit, n[c]-'0' );
                mindigit = min(mindigit, n[c]-'0' );
                
            }
            int sum = maxdigit - mindigit;
            
            if(sum > maxrange){
                maxrange = sum;
                maxsum = nums[i];
            }
            else if(sum == maxrange) {
                maxsum += nums[i];
            }
        }
        return maxsum;
    }
};