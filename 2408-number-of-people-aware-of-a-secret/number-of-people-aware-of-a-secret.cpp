class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD=1e9+7;

        vector<long long>dp(n+1,0);
        dp[1]=1;

        int shares=0;
        for(int day=2;day<=n;day++){

            if(day-delay>=1){
                shares=(shares+dp[day-delay])%MOD;
            }

            if(day-forget>=1){
                shares=(shares-dp[day-forget]+MOD)%MOD;
            }

            dp[day]=shares;
        }

        long long result=0;

        for(int day=n-forget+1;day<=n;day++){
            if(day>=1){
                result=(result+dp[day])%MOD;
            }
        }
        return(int)result;
    }
};