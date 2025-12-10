class Solution {
public:
    int mySqrt(int x) {
       if(x == 0 || x == 1)
        return x;

        int start = 1;
        int end = x;
        int mid ;

        while(start <= end){
            mid = start +(end - start)/2 ;

            if((long)mid * mid > (long)x)       //jab mid ka sq greater ho x se, change end to mid-1
                end = mid-1;
            
            else if(mid* mid == x)
                return mid;
            
            else
                start = mid +1;
        } 
        return floor(end);
    }
};
// The loop ends when "start" becomes greater than "end", and "end" is the integer value of the square root.
// However, since we might have been using integer division in the calculations,
// we round down the value of "end" to the nearest integer