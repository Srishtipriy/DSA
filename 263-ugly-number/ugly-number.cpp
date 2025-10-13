class Solution {
public:
    bool isUgly(int n) {
        if(n==1)        return true;
        if(n<=0)        return false;

        int ans= 0;
        while(n>1){
            if(n%2== 0){
                n/=2;
                ans= 1;
                continue;
            }
            if(n%3== 0){
                n/=3;
                ans= 1;
                continue;
            }
            if(n%5== 0){
                n/=5;
                ans= 1;
                continue;
            }
            else
                return false;
        }
        if(ans>0)       return true;
        else     return false;
    }
};