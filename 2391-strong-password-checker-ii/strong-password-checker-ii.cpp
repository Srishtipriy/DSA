class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool atleast8 = false;
        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool special_char = false;
        string special_charac = "!@#$%^&*()-+";

        int n  = password.length();
        if(n>=8){
            atleast8 = true;
        }else{
            return false;
        }

        for(int i = 1; i< n ; i++){
            if(password[i]==password[i-1]){
                return false;
            }
        }

        for(char c : password){
            if( c >= 'A' && c<= 'Z' ){
                uppercase= true;
            }else if( c >= 'a' && c<= 'z' ){
                lowercase= true;
            }else if(special_charac.find(c) != string::npos){
                special_char= true;
            }else if(c >= '0' && c<= '9'){
                digit = true;
            }
        }

        if(!uppercase || !lowercase || !digit || !special_char){
            return false;
        }
 
        return true;
    }
};