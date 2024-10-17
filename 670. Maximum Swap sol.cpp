class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();

        vector<int>v(n);
        v[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            int rightMaxIndex = v[i+1];
            int rightMaxElement = str[rightMaxIndex];

            v[i] = (str[i] > rightMaxElement) ? i : rightMaxIndex;
        }
        for(int i=0;i<n;i++)
        {
            int maxRightIndex = v[i];
            int maxRightElement = str[maxRightIndex];
            if(str[i] < maxRightElement)
            {
                swap(str[i],str[maxRightIndex]);
                return stoi(str);
            }
        }
        return num;
    }
};
