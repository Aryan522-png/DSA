class Solution {

private:
    int getpivot(vector<int>& nums){

        int s=0;
        int e=nums.size()-1;
        
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    } 

    int binarysearch(vector<int>& nums,int s,int e,int target){

        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;

    }
    


public:
    int search(vector<int>& nums, int target) {

        if(nums.empty()) return -1;

        int pivot=getpivot(nums);

        if(nums[pivot]==target){
            return pivot;
        }

        if(pivot==0){
            return binarysearch(nums,0,nums.size()-1,target);
        }
        if(target>=nums[0]){
            return binarysearch(nums,0,pivot-1,target);
        }
        
        return binarysearch(nums,pivot,nums.size()-1,target);
           
    }
};