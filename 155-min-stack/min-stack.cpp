#include<stack>
#include<climits>
class MinStack {

private:
    stack<long long> st;
    long long mini;    
public:
    MinStack() {

        while (!st.empty()) st.pop();

        mini = LLONG_MAX;
    }
    
    void push(int val) {

        long long value = val;

        if(st.empty()){
            st.push(value);

            mini=value;
        }

        else{

            if(value<mini){
                st.push(2*value-mini);
                mini=val;
            }
            else{
                st.push(value);
            }

        }
        
    }
    
    void pop() {

        if(st.empty()){
            return ;
        }

        long long curr=st.top();
        st.pop();

        if(curr<mini){

            mini=2*mini-curr;
        }

    }
    
    int top() {

        if(st.empty()){
            return -1;
        }
        long long curr=st.top();

        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }




        
    }
    
    int getMin() {

        if(st.empty()) return -1;
        
        return mini;
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */