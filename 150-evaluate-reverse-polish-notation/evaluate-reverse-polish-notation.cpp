class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>nums;

        for(const string& token : tokens){

            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                int result;

                if (token == "+") {
                    result = num1 + num2;
                } else if (token == "-") {
                    result = num1 - num2;
                } else if (token == "*") {
                    result = num1 * num2;
                } else if (token == "/") {
                    result = num1 / num2;
                }
                nums.push(result);
            }
            else{
                nums.push(stoi(token));
            }
        }

        return nums.top();

    }    
};