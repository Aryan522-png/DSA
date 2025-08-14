class Solution {
public:
    string largestGoodInteger(string num) {

        string result="";
        
        for (int i = 0;i <= num.size() - 3;i++){


            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string candidate=num.substr(i,3);

                if(candidate>result){
                    result=candidate;
                }
            }
        }
        return result;
    }
};