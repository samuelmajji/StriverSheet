#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return res;
    }
};

// Utility to print 2D vector
void printTriplets(const vector<vector<int>>& triplets) {
    for (const auto& triplet : triplets) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets with sum = 0:" << endl;
    printTriplets(result);

    return 0;
}