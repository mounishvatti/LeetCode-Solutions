#include <algorithm>
#include <iostream>
using namespace std;

struct Job
{
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
void printJobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Following is the maximum profit sequence of jobs:" << endl;
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}
int main()
{
    int n;

    cin >> n;
    Job arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    printJobScheduling(arr, n);

    return 0;
}
