class Solution {
public:
    bool isPalindrome(string s) {

        int l=0;
        int e=s.length()-1;

        while(l<e){

            while(l<e && !isalnum(static_cast<unsigned char>(s[l]))){
                l++;

            }

             while (l<e && !isalnum(static_cast<unsigned char>(s[e]))) {
                e--;
            }

            if(tolower(static_cast<unsigned char>(s[l])) != 
                tolower(static_cast<unsigned char>(s[e]))) {
                return false;
            }

            l++;
            e--;
        }

        return true;
    }
};