#include<iostream>
using namespace std;

int clumsyfact(int N)
{
  if(N==1)
    return 1;
  else if(N==2)
    return 2;
  else if(N==3)
    return 6;
  else if(N==4)
    return 7;
  else if(N%4==1 || N%4==2)
    return N+2;
  else if(N%4==3)
    return N-1;
  return N+1;
}

int main()
{
  int N;
  cin>>N;
  cout<<clumsyfact(N);
}
                                                                                                                            