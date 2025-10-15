class Solution {
public:
    bool isBalanced(string num) {
        int oddsum = 0;
        int evensum= 0;
        int i= 0;
        while(i < num.size()){
            int digit = num[i] - '0';
            if(i%2 ==0)
                evensum += digit;
            
            else  oddsum += digit;
            i++;
        }
        return (evensum == oddsum)? true : false ;
    }
};