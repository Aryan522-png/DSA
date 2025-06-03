class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
private:
    void mergesort(vector<int>&nums,int s,int e){

        if(s>=e) return;

        int mid=s+(e-s)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        merge(nums,s,mid,e);


    } 

    void merge(vector<int>&nums,int left,int mid,int right){
        vector<int>temp;

        int i=left;
        int j=mid+1;

        while(i<=mid && j<=right){

            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }

        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=right){
            temp.push_back(nums[j++]);
        }

        for(int k=0;k<temp.size();k++){
            nums[left+k]=temp[k] ;
        }   
    }
};