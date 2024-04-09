class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ticketsSold=0;
        while(true)
        {
            for(int i=0;i<n;i++)
            {
                if(tickets[i]>0)
                {
                    tickets[i]--;
                    ticketsSold++;
                }
                if(i==k && tickets[i]==0)
                {
                    return ticketsSold;
                }
            }
        }
        return 0;
    }
};
