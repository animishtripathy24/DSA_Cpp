class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int j=0;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]<a)
            {
                swap(array[i],array[j]);
                j++;
            }
        }
        for(int i=j;i<array.size();i++)
        {
            if(array[i]>=a && array[i]<=b)
            {
                swap(array[i],array[j]);
                j++;
            }
        }
        
    }
};
