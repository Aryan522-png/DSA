class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};

        vector<char>v;
        for(char c:s){
            if(vowels.count(c)){
                v.push_back(c);
            }
        }

        sort(v.begin(),v.end());

        int index=0;
        for(char &c:s){
            if(vowels.count(c)){
                c=v[index++];
            }
        }
        return s;
    }
};