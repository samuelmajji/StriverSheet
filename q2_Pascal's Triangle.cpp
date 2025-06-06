#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1}); // First row is always [1]

        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1); // Edges are always 1
                } else {
                    row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}