class Solution {
private:

    void sort(vector<int>& nums,int s,int e){

        int mid=s+(e-s)/2;

        int len1=mid-s+1;
        int len2=e-mid;

        vector<int>part1(len1);
        vector<int>part2(len2);


        for(int i=0;i<len1;i++){
            part1[i]=nums[s+i];
        }

        for(int i=0;i<len2;i++){

            part2[i]=nums[mid+1+i];

        }

        int index1=0;
        int index2=0;
        int k=s;

        while(index1<len1 && index2<len2){
            if(part1[index1]<part2[index2]){
                nums[k++]=part1[index1++];
            }
            else{
                nums[k++]=part2[index2++];
            }
        }

        while(index1<len1){
            nums[k++]=part1[index1++];
        }
        while(index2<len2){
            nums[k++]=part2[index2++];
        }


    }
    void merge(vector<int>& nums,int s,int e) {

        if(s>=e) return ;

        int mid=s+(e-s)/2;

        merge(nums,s,mid);
        merge(nums,mid+1,e);

        sort(nums,s,e);


    }   
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n=nums.size();
        int s=0;
        int e=n-1;

        merge(nums,s,e);
        return nums[n-k];
        
    }
};