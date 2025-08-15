class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1) return s;

        vector<string>rows(min(numRows,int (s.size())));
        
        int currrow=0;
        bool goingdown=false;

        for(char ch:s){
            rows[currrow]+=ch;

            if(currrow==0 || currrow==numRows-1){
                goingdown=!goingdown;
            }
            currrow+=goingdown? 1:-1;

        }
        string result;

        for(string row : rows){
            result+=row;
        }

        return result;
        
    }
};