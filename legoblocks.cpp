#include <iostream>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ull;
ull dp[1001];   // with rep
ull dpr1[1001]; // with rep
ull dpr2[1001]; // with rep
ull poww(ull x, int n)
{
    if (n == 0)
        return 1;
    ull t = poww(x, n / 2);
    t = t * t;
    if (t >= MOD)
        t %= MOD;
    if (n & 1)
    {
        t = t * x;
        if (t >= MOD)
            t %= MOD;
    }
    return t;
}
void pre()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    for (int i = 5; i <= 1000; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
        if (dp[i] >= MOD)
            dp[i] %= MOD;
    }
}
ull calc(int N, int M)
{
    for (int i = 1; i <= N; i++)
    {
        dpr1[i] = poww(dp[i], M);
    }
    for (int i = 1; i <= N; i++)
    {
        dpr2[i] = dpr1[i];
        for (int k = 1; k < i; k++)
        {
            ull x = dpr2[k];
            x = x * dpr1[i - k];
            if (x >= MOD)
                x %= MOD;
            dpr2[i] -= x;
            if (dpr2[i] >= MOD)
                dpr2[i] += MOD;
        }
    }
    return dpr2[N];
}
int main()
{
    pre();
    int N, M;
    cin >> N >> M;
    cout << calc(M, N) << endl;
}
