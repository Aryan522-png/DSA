class Solution {
private:

vector<int>nextsmallerelement(vector<int>& heights,int n){

    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        ans[i]= st.empty() ? n : st.top(); 
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
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;

}

int largestRectangleArea(vector<int>& heights,int n) {

    vector<int> next = nextsmallerelement(heights, n);
    vector<int> prev = prevsmallerelement(heights, n);


    int area=0;

    for(int i=0;i<n;i++){

        if(next[i]==-1){
            next[i]=n;
        }
        


        int l=heights[i];
        int b=next[i]-prev[i]-1;

       
        int newarea=l*b;
        area=max(newarea,area);
    }

    return area;
        
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows=matrix.size();

        if(rows==0) return 0;
        int columns=matrix[0].size();

        vector<int>heights(columns,0);

        int area=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){

                if(matrix[i][j]=='1'){
                    heights[j]++;
                } 
                else{
                    heights[j]=0;
                }
            }

            area=max(area,largestRectangleArea(heights,columns));
        }

        return area;

    }
};