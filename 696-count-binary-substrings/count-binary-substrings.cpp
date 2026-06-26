class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>ans;
        int c=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else{
                ans.push_back(c);
                c=1;
            }
        }
        ans.push_back(c);
        int res=0;
        for(int i=0;i<ans.size()-1;i++){
            res+=min(ans[i],ans[i+1]);
        }
        return res;
        
    }
};
