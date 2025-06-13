#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0;
        int fmax = 0;

        for (int num : nums) {
            if (num == 1) {
                temp++;
            } else {
                temp = 0;
            }
            fmax = max(fmax, temp);
        }

        return fmax;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    // Function call
    int result = sol.findMaxConsecutiveOnes(nums);

    // Output result
    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}