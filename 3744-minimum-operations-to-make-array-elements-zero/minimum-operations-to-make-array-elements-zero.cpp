class Solution {
public:

    long long getops(long long n){
        if (n<0){
            return 0;
        }
        long long res=0;
        long long ops=0;
        long long poweroffour=1;

        while(poweroffour<=n){
            long long l=poweroffour;
            long long r=min(n,poweroffour*4-1);
            ops++;
            res+=(r-l+1)*ops;
            poweroffour*=4;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {

        long long ans=0;
        for(auto&q : queries){
            long long l=q[0],r=q[1];
            ans+=(getops(r)-getops(l-1)+1)/2;
        }

        return ans;
        
    }
};