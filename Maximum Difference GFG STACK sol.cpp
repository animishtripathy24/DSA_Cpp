class Solution {
  private:
    vector<int> NSE(vector<int>&arr)
    {
        stack<int>s;
        vector<int>nge(arr.size(),-1);
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() && arr[i] < arr[s.top()])
            {
                nge[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
    vector<int> PSE(vector<int>&arr)
    {
        stack<int>s;
        vector<int>nge(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!s.empty() && arr[i] < arr[s.top()])
            {
                nge[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &heights) {
        int n=heights.size();
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);

        for(int i=0;i<nse.size();i++)
        {
            if(nse[i] == -1)
            {
                nse[i]=0;
            }
            if(pse[i]==-1)
            {
                pse[i]=0;
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            int abso = abs(nse[i]-pse[i]);
            maxi = max(maxi,abso);
        }
        return maxi;
    }
};
