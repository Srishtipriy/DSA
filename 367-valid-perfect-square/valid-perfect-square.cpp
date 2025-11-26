class Solution {
public:
    bool isPerfectSquare(int num) {
        int sub;
        for(int i=1 ;i<= num; i+=2){
            num = num - i;
            while(num == 0){
                return true;
            }
            
        }
        return false;
    }
};