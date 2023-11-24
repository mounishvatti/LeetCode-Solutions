#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int minSteps(int target, vector<int>& candies) 
{
    priority_queue<int, vector<int>, greater<int>> pq(candies.begin(), 
    candies.end());
    int steps = 0;
    while (pq.size() > 1 && pq.top() < target) 
    {
        int leastSweet = pq.top(); pq.pop();
        int secondLeastSweet = pq.top(); pq.pop();
        int newSweetness = leastSweet + 2 * secondLeastSweet;
        pq.push(newSweetness);
        steps++;
    }
    return pq.top() >= target ? steps : -1;
}
int main() 
{
    int target;
    cin >> target;
    vector<int> candies;
    int candy;
    while (cin >> candy)
        candies.push_back(candy);
    cout << minSteps(target, candies) << endl;
    return 0;
}