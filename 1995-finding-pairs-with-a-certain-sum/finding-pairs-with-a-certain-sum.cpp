class FindSumPairs {

    vector<int>& nums1;
    vector<int> nums2;

    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1), nums2(nums2) 
    {

        for(int num:nums2){
            freq[num]++;
        }
    }
    
    void add(int index, int val) {

        int old_val=nums2[index];
        freq[old_val]--;

        if(freq[old_val]==0) freq.erase(old_val);
        nums2[index]=nums2[index]+val;

        freq[nums2[index]]++;



    }
    
    int count(int tot) {

        int res=0;
        for(int num:nums1){
            int target=tot-num;
            if(freq.count(target)){
                res=res+freq[target];
            }
        }
        return res;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */