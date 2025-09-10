class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<unordered_set<int>>lang(m);

        for(int i=0;i<languages.size();i++){
            for(int l:languages[i]){
                lang[i].insert(l);
            }
        }

        unordered_set<int>need;

        for(auto &f:friendships){

            int u=f[0]-1;
            int v=f[1]-1;

            bool can=false;
            for(int l:lang[u]){
                if(lang[v].count(l)){
                    can=true;
                    break;
                }
            }

            if(!can){
                need.insert(u);
                need.insert(v);
            }
        }

        if(need.empty()) return 0;

        int res=INT_MAX;

        for(int l=1;l<=n;l++){
            int cnt=0;
            for(int n:need){
                if(!lang[n].count(l)) cnt++;
            }
            res=min(res,cnt);
        }

        return res;
    }
};