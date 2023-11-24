#include <iostream>
#include <vector>
using namespace std;
vector<int> egyptianFraction(int nr, int dr) 
{
    vector<int> ef;
    while (nr != 0) 
    {
        int x = dr / nr;
        if (dr % nr)
            x++;
        ef.push_back(x);
        nr = x * nr - dr;
        dr = dr * x;
    }
    return ef;
}

int main() 
{
    int nr , dr ;
    cin>>nr>>dr;
    vector<int> ef = egyptianFraction(nr, dr);
    for (int i = 0; i < ef.size(); i++)
        cout << ef[i] << "\n";
    return 0;
}