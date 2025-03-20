class Solution {
private:
    void solve(const string&digits,vector<string>&ans,string current,const string mapping[],int index){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }

        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            current.push_back(value[i]);
            solve(digits,ans,current,mapping,index+1);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()){
            return{};
        }
        

        const string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int index=0;

        solve(digits,ans,"",mapping,index);
        return ans;

        
    }
};