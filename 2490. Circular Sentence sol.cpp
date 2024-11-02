class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0] != sentence[n-1])
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(sentence[i] == ' ')
            {
                if((i+1 < n) && (sentence[i-1] != sentence[i+1]))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
