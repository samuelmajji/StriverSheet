#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    // Calculate trapped water
    int result = sol.trap(height);

    // Output
    cout << "Total trapped rain water: " << result << endl;

    return 0;
}