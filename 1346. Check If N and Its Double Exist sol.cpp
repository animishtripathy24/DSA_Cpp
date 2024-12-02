class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && arr[j]*2 == arr[i])
                {
                    return 1;
                }
            }
        } 
        return 0;
    }
};
