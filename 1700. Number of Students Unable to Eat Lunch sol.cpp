class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int>count;
        for(int i=0;i<students.size();i++)
        {
            count[students[i]]++;
        }
        int remaining = sandwiches.size();
        for(auto &sandwitch:sandwiches)
        {
            if(count[sandwitch]==0)
            {
                break;
            }
            if(remaining == 0)
            {
                break;
            }
            count[sandwitch]--;
            remaining--;
        }
        return remaining;
    }
};
