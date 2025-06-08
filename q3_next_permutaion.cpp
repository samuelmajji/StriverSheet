#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        
        // Step 1: Find the first decreasing element from the back
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: Find the next larger element from the back and swap
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements from i+1 to end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main(){
    
}