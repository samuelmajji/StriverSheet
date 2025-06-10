#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    long long int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Merging and counting inversions
        int i = left, j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
                count += (mid - i + 1); // Count inversions
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        // Copy sorted elements back
        for (int k = left; k <= right; k++) nums[k] = temp[k - left];

        return count;
    }

    long long int numberOfInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
int main(){
    return 0;
}
