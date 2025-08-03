class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>sumcount;
        sumcount[0]=1;

        int sum=0;
        int count=0;

        for(int i:nums){
            sum=sum+i;

            if(sumcount.count(sum-k)){
                count+=sumcount[sum-k];
            }
            sumcount[sum]++;
        }
        return count;
    }
};