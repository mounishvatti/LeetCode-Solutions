#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k);
};

int Solution::minimumNumbers(int num, int k) {
    if (num == 0) return 0;
    for (int i = 1; i <= num; ++i) {
        int t = num - k * i;
        if (t >= 0 && t % 10 == 0) return i;
    }
    return -1;
}

int main() {
    int num, k;
    string input;
    getline(cin, input);
    if (input.empty()) {
        num = 0;
    } else {
        num = stoi(input);
    }
    getline(cin, input);
    if (input.empty()) {
        k = 0;
    } else {
        k = stoi(input);
    }
    Solution s;
    cout << s.minimumNumbers(num, k) << endl;
    return 0;
}