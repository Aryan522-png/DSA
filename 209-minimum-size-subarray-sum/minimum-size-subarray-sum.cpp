class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum=0;
        int minlen=INT_MAX;

        int left=0;

        for(int right=0;right<nums.size();right++){

            sum=sum+nums[right];

            while(sum>=target){
                minlen=min(right-left+1,minlen);
                sum=sum-nums[left];
                left++;
            }
        }

        return minlen == INT_MAX?0 : minlen;
        
    }
};