class Solution {
private:
    int convert2Number(string& str) {
        int number = 0;
        for (int i = 0; i < str.size(); i++) {
            number = number * 10 + (str[i] - 48);
        }
        return number;
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto& it : timePoints) {
            stringstream ss(it);
            string token = "";
            int totalMinutes = 0;
            while (getline(ss, token, ':')) {
                int number = convert2Number(token);
                totalMinutes = totalMinutes * 60 + number;
            }
            minutes.push_back(totalMinutes);
        }
        sort(begin(minutes), end(minutes));
        int mini = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            mini = min(mini, (minutes[i] - minutes[i - 1]));
        }
        return min(mini, (24 * 60 - minutes[minutes.size() - 1] + minutes[0]));
    }
};
