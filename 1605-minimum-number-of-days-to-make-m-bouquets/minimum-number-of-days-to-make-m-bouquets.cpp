class Solution {
public:
    bool isItPossible(int n, vector<int>& bloomDay, int b, int k, int m){
        int countBoquests = 0;
        int countFlowers = 0;
        int i = 0;
        while(i < n){
            if(bloomDay[i] <= m)  countFlowers++;       //if arr mai day chota hai m se
            else countFlowers = 0;

            if(countFlowers == k){
                countBoquests++;            // 1 bouquet ready now flowerseq again 0 se start karo
                countFlowers = 0;
            }
            i++;        
        }
        if(countBoquests >= b) return true;             //req no. of bouquets prep ho gaye 

        return false;                                   // req b prep nhi hue
    }
    int minDays(vector<int>& bloomDay, int b, int k) {    
        int n = bloomDay.size(), m;
        if(1L*b*k > n) return -1;

        int l = 1, h = 1e9;
        int ans = INT_MAX;

        while(l <= h){
            m = (l+h)/2;
            bool possible = isItPossible(n,bloomDay, b, k, m);
            if(possible){
                ans = min(ans, m);
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};