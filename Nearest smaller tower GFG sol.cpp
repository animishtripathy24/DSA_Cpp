class Solution
{
private:
    vector<int> NSE(vector<int>&arr)
    {
        stack<int>s;
        vector<int>nge(arr.size(),-1);
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() && arr[i] < arr[s.top()])
            {
                nge[s.top()]=i;
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
                nge[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int>nse=NSE(arr);
        vector<int>pse=PSE(arr);
        // for(auto &it:nse)
        // {
        //     cout << it << " ";
        // }cout << endl;
        // for(auto &it:pse)
        // {
        //     cout << it << " ";
        // }cout << endl;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            
            if(nse[i]==-1 && pse[i]==-1)
            {
                ans[i]=-1;
            }
            else if(nse[i]==-1 && pse[i] != -1)
            {
                ans[i]=pse[i];
            }
            else if(nse[i]!=-1 && pse[i]==-1)
            {
                ans[i]=nse[i];
            }
            else
            {
                int mini_NSE=abs(nse[i]-i);
                int mini_PSE=abs(pse[i]-i);
                if(mini_NSE==mini_PSE)
                {
                    if(nse[i]==-1)
                    {
                        ans[i]=pse[i];
                    }
                    else if(pse[i]==-1)
                    {
                        ans[i]=nse[i];
                    }
                    else
                    {
                        if(arr[nse[i]]<arr[pse[i]])
                        {
                            ans[i]=nse[i];
                        }
                        else
                        {
                            ans[i]=pse[i];
                        }
                    }
                }
                else
                {
                    int mini=min(mini_NSE,mini_PSE);
                    if(mini==mini_NSE)
                    {
                        ans[i]=nse[i];
                    }
                    else
                    {
                        ans[i]=pse[i];
                    }
                }
            }
        }
        return ans;
    }
};
