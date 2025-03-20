class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 ||(x%10==0 && x!=0)||x<INT_MIN &&x>INT_MAX){
            return false;

        }
        int original=x;
        int ans=0;
        while(x>0){
            int digit=x%10;
            if(ans>INT_MAX/10){
                return false;
            }
            ans=ans*10+digit;
            x=x/10;
        }
       return original==ans;
    }
    
};