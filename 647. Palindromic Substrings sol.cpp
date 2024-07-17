class Solution {
private:
    void check(int i, int j, string& s, int n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }

public:
    int count = 0;
    int countSubstrings(string s) {
        int n = s.size();
        count = 0;
        for (int i = 0; i < s.size(); i++) {
            check(i, i, s, n);     // Odd length palindromes
            check(i, i + 1, s, n); // Even length palindromes
        }
        return count;
    }
};
