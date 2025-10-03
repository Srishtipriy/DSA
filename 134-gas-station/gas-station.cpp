class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance = 0;  // current tank balance
        int deficit = 0;  // total deficit when balance falls below 0

        for(int i = 0; i < gas.size(); i++){
            balance += gas[i] - cost[i];
            
            if(balance < 0) {
                // Can't reach station i+1 from current start
                deficit += balance;
                start = i + 1;  
                balance = 0;    // reset balance
            }
        }

        // If total gas >= total cost → possible
        if(balance + deficit >= 0)
            return start;
        else
            return -1;
    }
};
