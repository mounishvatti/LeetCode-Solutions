#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX;
        int profit = 0;
        int pist = 0;
        for (int i = 0; i < n; i++) {
            if (min > prices[i]) {
                min = prices[i];
            }
            pist = prices[i] - min;
            if (profit < pist) {
                profit = pist;
            }
        }
        return profit;
    }
};