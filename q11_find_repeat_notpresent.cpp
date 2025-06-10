#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        vector<int> ans(2, -1); // Ensure ans has 2 elements
        int n = nums.size();

        // Using index marking technique
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]);  // Get absolute value
            if (nums[idx - 1] < 0) { // If already marked negative, it's the duplicate
                ans[0] = idx;
            } else {
                nums[idx - 1] = -nums[idx - 1]; // Mark visited
            }
        }

        // Find missing number by scanning for unmarked index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[1] = i + 1; // Missing number
                break;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 6, 2, 1, 1}; // Example input
    Solution sol;
    vector<int> result = sol.findMissingRepeatingNumbers(nums);

    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
