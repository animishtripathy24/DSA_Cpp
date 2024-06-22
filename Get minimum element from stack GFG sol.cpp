class Solution{
    int minEle;
    stack<pair<int,int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(!s.empty())
           {
               return s.top().second;
           }
           return -1;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
            if(!s.empty())
            {
                int top=s.top().first;
                s.pop();
                return top;
            }
            else
            {
                return -1;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           //if it is the first element
           if(s.empty())
           {
               s.push({x,x});
           }
           else
           {
               int minTop=s.top().second;
               s.push({x,min(x,minTop)});
           }
       }
};
