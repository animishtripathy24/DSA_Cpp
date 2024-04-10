class Solution{
private:
    vector<int>NGE(int n,int arr[],unordered_map<int,int>&m)
    {
        vector<int>nge(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && m[arr[s.top()]]<m[arr[i]])
            {
                nge[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        vector<int>nge=NGE(n,arr,m);
        return nge;
    }
};
