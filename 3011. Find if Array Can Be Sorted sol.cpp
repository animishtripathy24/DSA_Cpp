class Solution {
public:
    bool canSortArray(vector<int>& arr) {
        int n = arr.size();
        bool did_i_swap = false;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                if ((arr[j] > arr[j + 1])) {
                    if ((__builtin_popcount(arr[j]) ==
                         __builtin_popcount(arr[j + 1]))) {
                        swap(arr[j], arr[j + 1]);
                        did_i_swap = true;
                    }
                }
            }
            if (!did_i_swap) {
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
