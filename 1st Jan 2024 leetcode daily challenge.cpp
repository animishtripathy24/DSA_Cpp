class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //initialize the counter variable
        int count=0;
        //if the cookie wala array has size 0
        if(s.size()==0) return 0;
        //sort the two vectors
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //at first we have to find the index of the last element
        int cookie=s.size()-1;
        int child=g.size()-1;
        while(cookie>=0 && child >=0)
        {
            if(s[cookie]>=g[child])
            {
                count++;
                cookie--;
                child--;
            }
            else
            {
                child--;
            }
        }  
        return count;      
    }
};
