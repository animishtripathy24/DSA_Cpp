class Solution {
private:
    void levenstein(string str1, string str2, vector<vector<int>>& v) {
        int n = str1.size();
        int m = str2.size();
        
        // Adding the extra space at the beginning
        str1 = " " + str1;
        str2 = " " + str2;
        
        // Filling the matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i] != str2[j]) {
                    v[i][j] = 1 + min(v[i-1][j], min(v[i-1][j-1], v[i][j-1]));
                } else {
                    v[i][j] = v[i-1][j-1];
                }
            }
        }
    }
public:
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // Initializing the matrix with size (n+1)x(m+1)
        vector<vector<int>> v(n+1, vector<int>(m+1, 0));
        
        // Base cases for the DP matrix
        for (int i = 0; i <= n; i++) {
            v[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            v[0][j] = j;
        }
        
        levenstein(str1, str2, v);
        return v[n][m];
    }
};
