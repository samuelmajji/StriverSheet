#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3}; // Example input
    Solution sol;
    int result = sol.majorityElement(nums);
    
    cout << "Majority Element: " << result << endl;
    
    return 0;
}
