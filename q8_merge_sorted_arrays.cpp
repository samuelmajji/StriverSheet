#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Index of last element in nums1's valid part
        int j = n - 1;         // Index of last element in nums2
        int k = m + n - 1;     // Index of last position in nums1 (including extra space)

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has remaining elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter the number of elements in nums1 (excluding extra space): ";
    cin >> m;
    cout << "Enter the number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements for nums1: ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter " << n << " sorted elements for nums2: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}