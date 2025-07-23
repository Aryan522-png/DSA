class Solution {
public:
    bool checkValidString(string s) {

        stack<char>openpara;
        stack<char>star;

        
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch=='('){

                openpara.push(i);

            }
            else if(ch=='*'){

                star.push(i);
            }

            else if(ch==')'){

                if(!openpara.empty()){
                    openpara.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }

        }

        while(!openpara.empty() && !star.empty() ){

            if(openpara.top()>star.top()){
                return false;
            }

            openpara.pop();
            star.pop();

        }

        return openpara.empty();

        
    }
};