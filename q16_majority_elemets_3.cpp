#include <vector>
#include <algorithm>  // for std::count
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return {};

        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        for (int n : nums) {
            if (n == candidate1) {
                count1++;
            } else if (n == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: validate candidates
        vector<int> result;
        int n_third = nums.size() / 3;
        if (count(nums.begin(), nums.end(), candidate1) > n_third)
            result.push_back(candidate1);
        if (candidate2 != candidate1 && count(nums.begin(), nums.end(), candidate2) > n_third)
            result.push_back(candidate2);

        return result;
    }
};