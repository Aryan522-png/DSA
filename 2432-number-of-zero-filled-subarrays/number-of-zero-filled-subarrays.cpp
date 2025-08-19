class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int countzeros=0;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                countzeros+=1;
                ans.push_back(i);
            }
        }

        long long subarray=0;
        long long streak=1;

        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]+1){

                streak++;
            }
            else{
                subarray+=(streak*(streak-1))/2;
                streak=1;
            }
        }

        if(!ans.empty()){
            subarray += (streak * (streak - 1)) / 2;
        }

        long long total=subarray+countzeros;
        return total;
    }
};