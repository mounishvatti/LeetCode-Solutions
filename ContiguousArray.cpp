#include <iostream>
#include <unordered_map>
using namespace std;
int doSomething(int nums[], int n) {
    unordered_map<int, int> map;
    map[0] = -1;
    int maxlen = 0, count = 0;
    for (int i = 0; i < n; i++) {
        count = count + (nums[i] == 1 ? 1 : -1);
        if (map.find(count) != map.end()) {
            maxlen = max(maxlen, i - map[count]);
        } else {
            map[count] = i;
        }
    }
    return maxlen;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int len = doSomething(nums, n);
    cout << len;
    return 0;
}