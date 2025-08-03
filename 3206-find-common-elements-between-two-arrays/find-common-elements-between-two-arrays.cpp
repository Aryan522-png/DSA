class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        
        int count1=0;
        for(int i:nums1){
            if(s2.count(i)){
                count1++;
            }
        }
        

        int count2=0;
        for(int j:nums2){
            if(s1.count(j)){
                count2++;
            }
        }

        return {count1,count2};
        
    }
};