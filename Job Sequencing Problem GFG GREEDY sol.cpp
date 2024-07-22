/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    bool static cmp(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr + n,cmp);
        int maxi = -1;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i].dead);
        }
        vector<int>days(maxi+1,-1);
        int totalProfit =0;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = arr[i].dead;j>0;j--)
            {
                if(days[j] == -1)
                {
                    count++;
                    days[j]=arr[i].id;
                    totalProfit+=arr[i].profit;
                    break;
                }
            }
        }
        return {count,totalProfit};
    } 
};
