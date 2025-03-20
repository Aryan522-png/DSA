class Solution {

private:
    bool search(vector<int>&row,int target){
        int s=0;
        int e=row.size()-1;
        
        while(s<=e){

            int mid=s+(e-s)/2;

            if(row[mid]==target){

                return true;
            }

            else if(row[mid]<target){
                s=mid+1;
            }

            else{
                e=mid-1;
            }

        }
        
        return false;

        
    }


    
    bool ispresent(vector<vector<int>>& matrix, int target){
        for(int i=0;i<matrix.size();i++){
            if(search(matrix[i],target)){
                return true;
            }
            
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        return ispresent(matrix,target);
        
    }
};