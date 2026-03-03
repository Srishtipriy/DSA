class Solution {
public:
    bool digitCount(string num) {
        map<int,int>idxCount , numCount;
        int n = num.size();

        for(int i = 0; i<n ; i++){
            numCount[num[i] - '0']++;       //numcount mai freq increase kr rahe h 

            if(num[i] != '0')
            {
                idxCount[i] = (num[i] - '0' );
            }
        }
        return idxCount == numCount;
    }
};
/*
numCount → har digit kitni baar aayi (actual frequency)
idxCount → index ke according expected frequency

*/