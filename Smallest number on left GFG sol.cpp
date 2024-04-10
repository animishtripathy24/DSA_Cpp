class Solution{
private: 
    vector<int> PSE(int n,int a[])
    {
        stack<int>s;
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[i] < a[s.top()])
            {
                nge[s.top()]=a[i];
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int>pse=PSE(n,a);
        return pse;
    }
};
