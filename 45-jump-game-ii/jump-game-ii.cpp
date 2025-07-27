class Solution {
public:
    int jump(vector<int>& nums) {

        int n=nums.size();

        if(n<=1){
            return 0;

        }

        int freespot=0;
        int currend=0;
        int jump=0;

        for(int i=0;i<n-1;++i){

            freespot=max(freespot,i+nums[i]);

            if(i==currend){
                jump++;
                currend=freespot;
            }
        }

        return jump;        
    }
};