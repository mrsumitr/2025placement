#Q1 682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto opn: operations){
            if(opn=="+" || opn=="D" || opn=="C"){
                
                int res=0;
                if(opn=="+"){
                    int b=st.top();
                    st.pop();
                    int a=st.top(); 
                    st.push(b);  
                    res=a+b;
                    st.push(res);
                }
                else if(opn=="D"){
                    int b=st.top();
                    st.push(2*b);
                }
                else{
                    st.pop();
                }
                
            }
            else{
                    st.push(stoi(opn));
                }
            
        
            
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
#Q2 726. Number of Atoms
