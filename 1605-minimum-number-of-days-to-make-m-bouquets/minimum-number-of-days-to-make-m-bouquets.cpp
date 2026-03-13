class Solution {
private:
    bool canMake(vector<int>& bloomDay, int m, int k, int day){   //day == mid
        int bouquets = 0, flowers = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0; }
            }
            else{
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL*m*k;
        if(need > bloomDay.size())
            return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canMake(bloomDay, m, k, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};