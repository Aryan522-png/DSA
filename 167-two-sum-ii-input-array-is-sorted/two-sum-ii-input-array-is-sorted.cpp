class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n=numbers.size();

        int index1=0;
        int index2=n-1;
        vector<int>solution;

        while(index1<index2){
            int sum=numbers[index1]+numbers[index2];
            if(sum==target){

                solution.push_back(index1+1);
                solution.push_back(index2+1);
                return solution;

            }
            else if(sum>target)
            {
                index2--;
            }
            else{
                index1++;
            }
        }

        return solution;
        
    }
};