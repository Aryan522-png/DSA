class Solution {

private:

vector<int>nextsmallerelement(vector<int>& heights,int n){

    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;

}
vector<int>prevsmallerelement(vector<int>& heights,int n){

    stack<int>st;
    vector<int>ans(n);

    for(int i=0;i<n;i++){

        while(!st.empty() &&  heights[st.top()] >= heights[i]){
            st.pop();
        }
        ans[i]= st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;

}
public:
    int largestRectangleArea(vector<int>& heights) {

       int n=heights.size();
       vector<int>next(n);

       next=nextsmallerelement(heights,n);

       vector<int>prev(n);
       prev=prevsmallerelement(heights,n);

       int area=0;

       for(int i=0;i<n;i++){



        int l=heights[i];
        int b=next[i]-prev[i]-1;

       
        int newarea=l*b;
        area=max(newarea,area);
       }

       return area;
        
    }
};