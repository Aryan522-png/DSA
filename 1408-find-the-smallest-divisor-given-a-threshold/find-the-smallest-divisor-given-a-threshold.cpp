class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maximum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maximum=max(nums[i],maximum);
        }


        int s=1;
        int e=maximum;
        

        int finalresult=maximum;

        while(s<=e){

            int mid=s+(e-s)/2;

            int sum=0;

            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }

            if(sum<=threshold){
                finalresult=mid;
                e=mid-1;

            }
            else{
                s=mid+1;
            }

        }
        return finalresult;

        


    


      

    }
};