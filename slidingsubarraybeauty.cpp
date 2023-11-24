#include <iostream>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
vector<int> slidingBeauty(vector<int>& nums, int k, int x) {
    map<int, int> m;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
        if (i >= k) {
            if (--m[nums[i-k]] == 0) {
                m.erase(nums[i-k]);
            }
        }
        if (i >= k - 1) {
            auto it = m.begin();
            advance(it, x - 1);
            res.push_back(it->first);
        }
    }
    return res;
}

int main() {
    vector<int> nums(10);
    for(int i = 0; i < 10; i++)
    {
        cin>>nums[i];
    }
    int k,x;
    cin>>k;
    cin>>x;
    vector<int> res = slidingBeauty(nums, k, x);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}