class Solution {
bool static cmp(Item a,Item b)
{
    return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
}
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        //we will sort the array according to the value / weight
        sort(arr,arr+n,cmp);
        double totalValue = 0.0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight <= w)
            {
                totalValue +=(double)arr[i].value;
                w = w - arr[i].weight;
            }
            else
            {
                double weightToBeAdded = ((double)arr[i].value/(double)arr[i].weight) * w;
                totalValue += weightToBeAdded;
                break;
            }
        }
        return totalValue;
    }
};
