#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int n;

    cout << "Enter number of days: ";
    cin >> n;

    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}