#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] < target) {
                    break; // Move to the next row
                } else {
                    if (matrix[i][j] == target) {
                        return true; // Found target
                    }
                }
            }
        }
        return false; // Target not found
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target;
    cout << "Enter target value: ";
    cin >> target;

    Solution sol;
    bool result = sol.searchMatrix(matrix, target);

    if (result) {
        cout << "Target " << target << " found in matrix." << endl;
    } else {
        cout << "Target " << target << " not found in matrix." << endl;
    }

    return 0;
}
