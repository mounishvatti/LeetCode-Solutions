#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<sstream>
using namespace std;
vector<int> smallestTrimmedNumbers(vector<string>& nums, 
vector<vector<int>>& queries) 
{
  vector<int> res;
  for(auto x:queries)
  {
    priority_queue<pair<string,int>> v;
    for(int i=0;i<nums.size();i++)
    {
      int t=nums[i].length()-x[1];
      string p=nums[i].substr(t,x[1]);
      if(v.size()<x[0])
        v.push({p,i});
      else
      {
        if(v.top().first > p)
        {
          v.pop();
          v.push({p,i});
        }
      }
    }
    int val=v.top().second;
    res.push_back(val);
  }
  return res;
}
vector<string> readVector() 
{
  vector<string> nums;
  string line;
  getline(cin, line);
  stringstream ss(line);
  string num;
  while (ss >> num) 
  {
    nums.push_back(num);
  }
  return nums;
}
vector<vector<int>> read2DVector(int q) 
{
  vector<vector<int>> queries;
  for (int i = 0; i < q; i++) 
  {
    vector<int> query(2);
    cin >> query[0] >> query[1];
    queries.push_back(query);
  }
  return queries;
}
int main() {
  vector<string> nums;
  int q;
  vector<vector<int>> queries;
  nums = readVector();
  cin >> q; 
  queries = read2DVector(q);
  vector<int> result = smallestTrimmedNumbers(nums, queries);
  for (int i = 0; i < result.size(); i++) 
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}