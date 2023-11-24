#include <iostream>
#include <vector>
using namespace std;
int maxArrayValue(int n, int q, vector<vector<int>>& queries) 
{
  vector<int> arr(n, 0);
  for (auto query : queries) 
  {
    int start = query[0] - 1;
    int end = query[1] - 1; 
    int value = query[2];
    for (int i = start; i <= end; i++) 
    {
      arr[i] += value;
    }
  }
  int max = 0;
  for (int num : arr) 
  {
    if (num > max) 
    {
      max = num;
    }
  }
  return max;
}
int main() 
{
  int n, q;
  vector<vector<int>> queries;
  cin >> n; 
  cin >> q;
  for (int i = 0; i < q; i++) 
  {
    vector<int> query(3);
    cin >> query[0] >> query[1] >> query[2];
    queries.push_back(query);
  }
  int result = maxArrayValue(n, q, queries);
  cout << result << endl;
  return 0;
}
                                                                                                                            