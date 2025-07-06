class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int i=0;
        int n=prices.size();
        int profit=0;

        while(i<n-1){

            while(i<n-1 && prices[i]>=prices[i+1]){
                i++;
            }

            if (i==n-1) break;
            int buyingprice=prices[i];
            i++;

            while(i<n && prices[i]>=prices[i-1]){
                i++;
            }

            int sellingprice=prices[i-1];

            profit+=sellingprice-buyingprice;

        }

        return profit;
        
    }
};