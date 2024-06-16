class Solution {
  private:
    vector<int> NGE(vector<int>&arr,int N)
    {
        vector<int>nge(N,-1);
        stack<int>s;
        for(int i=0;i<2*N;i++)
        {
            while(!s.empty() && arr[i%N]>arr[s.top()%N])
            {
                nge[s.top()%N]=arr[i%N];
                s.pop();
            }
            s.push(i%N);
        }
        return nge;
    }
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        vector<int>nge = NGE(arr,N);
        return nge;
    }
};
