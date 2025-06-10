#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int idx = abs(nums[i]); // Get absolute value (since nums[idx] might be negative)
            if (nums[idx] < 0) {    // If already visited (negative), return the duplicate
                return idx;
            }
            nums[idx] = -nums[idx]; // Mark as visited
        }
        return n; // Should never reach here if input is valid
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    Solution sol;
    int duplicate = sol.findDuplicate(nums);
    
    cout << "The duplicate number is: " << duplicate << endl;
    
    return 0;
}
