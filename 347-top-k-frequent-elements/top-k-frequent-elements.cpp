class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        if(nums.size()<=1){
            return nums;
        }

        unordered_map<int,vector<int>>mp;

        for( int i=0;i<nums.size();i++){

            int val=nums[i];
            mp[val].push_back(val);

        }

        vector<pair<int,int>>freqlist;

        for(auto& it:mp){
            freqlist.push_back({it.second.size(),it.first});
        }

        sort(freqlist.rbegin(), freqlist.rend());

        vector<int>result;

        for(int i=0;i<k && i<freqlist.size() ;i++){

            result.push_back(freqlist[i].second);
        }

        return result;

        
        
    }
};