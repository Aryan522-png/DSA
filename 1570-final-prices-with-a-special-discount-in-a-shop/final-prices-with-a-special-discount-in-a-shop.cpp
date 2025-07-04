class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();

        stack<int>st;
        

        vector<int>ans(n);

        for(int i=n-1;i>=0;i--){

            int curr=prices[i];

            while(!st.empty() && st.top()>curr){
                st.pop();
            }
            ans[i]=(!st.empty())?st.top():0;
            st.push(curr);
        }


        vector<int>finalans;
        int m=ans.size();

        for(int i=0;i<m;i++){

            finalans.push_back(prices[i] - ans[i]);

        }
        return finalans;
    }
};