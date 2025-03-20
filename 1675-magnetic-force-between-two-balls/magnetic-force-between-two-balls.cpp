class Solution {
private:
bool  ispossible(vector<int>& position, int m,int mid){
    int count=1;
    int lastpos=position[0];
    for(int i=1;i<position.size();i++){

        if(position[i]-lastpos>=mid){
            count++;
            if(count==m){
                return true;
            }
            lastpos=position[i];
            

        }

    }
    return false;
}
public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());

        int s=0;
        int e=position.back()-position.front();

        int mid=s+(e-s)/2;
        int ans=-1;

        while(s<=e){

            if(ispossible(position,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;

        }
        return ans;

    }
};