class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();

        vector<int>ans(n,0);

        vector<pair<int,int>>numindex;

        for(int i=0;i<n;++i){
            numindex.push_back({nums[i],i});

        }
        mergesort(numindex,0,n-1,ans);
        return ans;
        
    }

    void mergesort(vector<pair<int,int>>&vec,int left,int right,vector<int>&ans){
        if(left>=right)return;

        int mid=(left+right)/2;

        mergesort(vec,left,mid,ans);
        mergesort(vec,mid+1,right,ans);

        vector<pair<int, int>> temp;
        int i = left, j = mid + 1, rightCount = 0;

        while(i<=mid && j<=right){
            if (vec[i].first <= vec[j].first){

                ans[vec[i].second] += rightCount;
                temp.push_back(vec[i++]);
            }
            else{
                rightCount++;
                temp.push_back(vec[j++]);
            }    
        }
        while (i <= mid) {
            ans[vec[i].second] += rightCount;
            temp.push_back(vec[i++]);
        }

        while (j <= right) temp.push_back(vec[j++]);

        for (int k = left; k <= right; ++k) {
            vec[k] = temp[k - left];
        }
    }
};