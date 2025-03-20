class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0;
        int j=height.size()-1;
        int max_area=0;
        while(i<j){
            int width=j-i;
            int area;
            if(height[i]>height[j]){
                area=width*height[j];
                j--;
                
          

            }else{
                area=width*height[i];
                i++;
          
            }
            if(area>max_area){
                    
                max_area=area;
            }
            
            
        }
        cout<<"the maximum area is:"<<max_area<<endl;
        return max_area;
    }    
    
};