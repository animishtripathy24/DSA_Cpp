class Solution
{
    public:
    string rearrangeString(string str)
    {
        int n=str.size();
        
        //then we have to declare a unordered map to keep track of the frequency
        map<char,int>m;
        for(int i=0;i<str.size();i++)
        {
            m[str[i]]++;
        }
        //then we have to keep track of the maximum character with its frquency
        //for this we have to declare a max heap
        priority_queue<pair<int,char>>pq;
        
        for(auto &it:m)
        {
            pq.push({it.second,it.first});
        }
        string ans(str.size(),'A');
        int index=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            char ch=it.second;
            int count=it.first;
            
            while(count > 0)
            {
                //if the index reaches n
                if(index >= str.size())
                {
                    index=1;
                }
                ans[index]=ch;
                count--;
                index+=2;
            }
        }
        // for(auto &ch:ans)
        // {
        //     cout << ch << " ";
        // }
        // check if there is no adjacent character present in the string 
        for(int i=0;i<n-1;i++)
        {
            if(ans[i]==ans[i+1])
            {
                return "-1";
            }
        }
        return ans;
    }
    
};
