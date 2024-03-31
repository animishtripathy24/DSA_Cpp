/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
private:
    long long merge(vector<long long>& arr, int low, int mid, int high) {
        vector<long long> temp;
        long long int count = 0;
        int i = low;
        int j = mid + 1;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                count += mid - i + 1;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
        while (j <= high) {
            temp.push_back(arr[j++]);
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return count;
    }

    long long mergeSort(vector<long long>& arr, int low, int high) {
        long long count = 0;
        if (low >= high) return count;
        int mid = (low + high) >> 1;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }

    long long getInversions(vector<long long>& arr, int n) {
        return mergeSort(arr, 0, n - 1);
    }

    void inorder(Node* root, vector<long long>& arr) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

public:
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node* root) {
        vector<long long> arr;
        inorder(root, arr);
        return getInversions(arr, n);
    }
};
