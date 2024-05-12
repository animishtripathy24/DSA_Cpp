class Solution {
  public:
    int minSteps(int d) {
        int count=0;
        int steps=0;
        while(count < d)
        {
            steps++;
            count+=steps;
        }
        
        while((count-d) & 1)
        {
            steps++;
            count+=steps;
        }
        return steps;
    }
};
