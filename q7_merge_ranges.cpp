#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0) return ans;

        sort(intervals.begin(), intervals.end());
        vector<int> current = intervals[0];

        for (int i = 1; i < n; i++) {
            if (current[1] >= intervals[i][0]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter intervals as pairs [start end]:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged Intervals:\n";
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}