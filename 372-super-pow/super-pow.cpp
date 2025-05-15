class Solution {

int modpow(int a ,int k,int mod){

    int res=1;

    for(int i=0;i<k;++i){
        res=((long long)res*a)%mod;
    }
    return res;
}

public:
    int superPow(int a, vector<int>& b) {

        if(b.empty()){
            return 1;
        }

        int lastdigit=b.back();
        b.pop_back();

        int part1=modpow(a,lastdigit,1337);
        int part2=modpow(superPow(a,b),10,1337);

        return (part1*part2)%1337;
        
    }
};