#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        int n = nums.size();

        // Count 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) c0++;
            else if (nums[i] == 1) c1++;
            else if (nums[i] == 2) c2++;
        }

        // Overwrite nums based on counts
        for (int i = 0; i < n; i++) {
            if (c0 > 0) {
                nums[i] = 0;
                c0--;
            } else if (c1 > 0) {
                nums[i] = 1;
                c1--;
            } else {
                nums[i] = 2;
                c2--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (only 0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}