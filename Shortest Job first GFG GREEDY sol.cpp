class Solution {
  public:
    long long solve(vector<int>& bt) {
        //at first we will sort the burst array
        sort(begin(bt),end(bt));
        long long int time = 0;
        long long int waitingTime = 0;
        for(int i=0;i<bt.size();i++)
        {
            waitingTime += time;
            time += bt[i];
        }
        return (long long)(waitingTime/bt.size());
    }
};
