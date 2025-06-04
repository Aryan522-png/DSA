class Solution {
public:
    int mySqrt(int x) {

        int s=0;
        int e=x;
        int mid=s+(e-s)/2;

        while(s<=e){

            mid=s+(e-s)/2;
            long long mul=(long long)mid*mid;
            if(mul==x){
                return mid;
            }
            if(mul>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return e;
        
    }
};