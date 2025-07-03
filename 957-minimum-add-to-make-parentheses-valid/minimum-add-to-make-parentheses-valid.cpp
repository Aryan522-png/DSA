class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> str;
        for (char ch : s) {
            if (!str.empty() && str.top() == '(' && ch == ')') {
                str.pop();
            } else {
                str.push(ch);
            }
        }
        return str.size();  
    }
};
