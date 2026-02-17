class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> temp(n+1);

        for(int i=0; i<n+1; i++){
            int nums = i;       //no touching of i
            int count = 0;

            while(nums){
                nums = nums & (nums-1);
                count++;
            }
            temp[i] = count;        //yeh tabhi use karte h jab vec size fix ho
        }
        return temp;
    }
};