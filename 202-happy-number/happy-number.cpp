class Solution {
public:
    bool isHappy(int n) {

        if(n==1 )   return true;
        if(n==7 )   return true;
        else if(n<10)   return false;

        else{
            int sum=0;
            while(n>0){
                int a = n%10;
                sum= sum+ ( a * a );
                n=n/10;
            }
            return isHappy(sum);
        }
    }
};