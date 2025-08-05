class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n=nums.size();
        int count=n/3;

        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        vector<int>ans;

        for(auto i:mp){
            if(i.second>count){
                ans.push_back(i.first);
            }
        }

        return ans;
        
    }
};