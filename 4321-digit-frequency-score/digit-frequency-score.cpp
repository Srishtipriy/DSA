class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum =0;
        unordered_map<int,int> mp;

        while(n > 0){
            int digit = n % 10;
            mp[digit]++;
            n = n/10;
        }
        for(auto c : mp){
            sum += c.first*c.second;
        }
        return sum;
    }
};