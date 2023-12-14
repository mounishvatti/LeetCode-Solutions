#include <iostream>
#include <vector>
using namespace std;
int secretSpread(int n, int delay, int forget)
{
    vector<int> people(n + 1, 0);
    people[0] = 1;
    int total = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i - delay >= 0)
        {
            people[i] += people[i - delay];
        }
        if (i - forget >= 0)
        {
            people[i - forget] -= people[i - forget - delay];
        }
        total += people[i];
    }
    return total+1;
}
int main()
{
    int n, delay, forget;
    cin >> n >> delay >> forget;
    cout << secretSpread(n, delay, forget) << endl;
    return 0;
}