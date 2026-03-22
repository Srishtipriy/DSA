class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> dp(n,0);
        long long MOD = pow(10,9) + 7;
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()){
                dp[i] = ((arr[i] * (i - st.top())) %MOD + dp[st.top()] % MOD) % MOD;
            }
            else{
                dp[i] = (arr[i] * (i + 1)) % MOD;
            }
            st.push(i);
        }    
        long long ans =0;

        for(int i=0;i<n;i++){
            ans = (ans % MOD + dp[i] % MOD) % MOD;
        }
        return ans;
    }
};