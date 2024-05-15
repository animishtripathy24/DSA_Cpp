/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int peakIndex(MountainArray &mountainArr)
    {
        int start=0;
        int end=mountainArr.length()-1;

        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return start;
    }
    int binarySearch(MountainArray &mountainArr,int s,int e,int key)
    {
        int start=s;
        int end=e;

        while(start<=end)
        {
            int mid=start+((end-start)>>1);//to neglect integer overflow.

            if(mountainArr.get(mid)==key)
            {
                return mid;
            }
            else if(key>mountainArr.get(mid))
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
    int binarySearch2(MountainArray &mountainArr,int s,int e,int key)
    {
        int start=s;
        int end=e;

        while(start<=end)
        {
            int mid=start+((end-start)>>1);//to neglect integer overflow.

            if(mountainArr.get(mid)==key)
            {
                return mid;
            }
            else if(key>mountainArr.get(mid))
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakIndex(mountainArr);
        int index1=binarySearch(mountainArr,0,peak,target);
        int index2=binarySearch2(mountainArr,peak+1,mountainArr.length()-1,target);
        cout << index1 << "  " << index2 << endl;
        if(index1==-1 && index2 != -1)
        {
            return index2;
        }
        if(index1 != -1 && index2 == -1)
        {
            return index1;
        }
        return min(index1,index2);
    }
};
