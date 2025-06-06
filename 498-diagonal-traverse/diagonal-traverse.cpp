class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows=mat.size();
        if(rows==0) return{};
        int cols=mat[0].size();
        
        vector<int>result;

        for(int d=0;d<rows+cols-1;d++){

            vector<int>intermediate;

            int r=(d<cols)? 0:d-cols+1;
            int c=(d<cols)? d:cols-1;

            while(r<rows && c>=0){
                intermediate.push_back(mat[r][c]);
                r++;
                c--;
            }
            if(d%2==0){
                reverse(intermediate.begin(),intermediate.end());
            }
            result.insert(result.end(),intermediate.begin(),intermediate.end());
        }

        return result;
        
    }
};