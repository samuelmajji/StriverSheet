#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;  // Convert to long long to handle INT_MIN safely
        if (p < 0) {
            x = 1 / x;
            p = -p;
        }

        double ans = 1.0;
        while (p > 0) {
            if (p % 2 == 1) ans *= x;  // If power is odd, multiply result by x
            x *= x;  // Square the base
            p /= 2;  // Reduce the exponent
        }
        
        return ans;
    }
};

int main() {
    double x;
    int n;
    
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    Solution sol;
    double result = sol.myPow(x, n);

    cout << "Result: " << result << endl;

    return 0;
}
