class Solution {
public:
    string findValidPair(string s) {
        if (s.length() < 2) return "";

        vector<int> freq(10, 0);  //vector of 9+1 spaces with 0 filled
        for (char ch : s) {
            freq[ch - '0']++;       //feq count kar lo each ele ka
        }
        for(int i = 0; i< s.size()-1 ; i++){
            int first = s[i] - '0';
            int sec = s[i+1] - '0';

            if(first != sec){
                if( freq[first]== first && freq[sec] == sec ){
                    return string(1, s[i]) + string(1 , s[i+1] );
                }
            }
        }
        return "";
    }
};