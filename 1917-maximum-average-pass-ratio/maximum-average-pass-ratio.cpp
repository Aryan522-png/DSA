class Solution {
public:

    struct classinfo{
        int p;
        int t;

        double gain() const{
            return (double)(t-p)/(t*(t+1.0));
        }

        double ratio() const{

            return (double)p/t;

        }
    };

    struct compare{
        bool operator()(const classinfo&a,const classinfo&b){
            return a.gain()<b.gain();
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<classinfo,vector<classinfo>,compare>pq;

        for(auto& c : classes){

            pq.push({c[0],c[1]});

        }


        while(extraStudents--){
            auto best=pq.top();
            pq.pop();
            best.p+=1;
            best.t+=1;
            pq.push(best);
        }

        double sum=0;
        while(!pq.empty()){
            sum+=pq.top().ratio();
            pq.pop();
        }

        return sum/classes.size();
        
    }
};