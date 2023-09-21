#include <iostream>
#include <vector>

using namespace std;

int N, tmp;
vector<int> v;
int dp[301];

int Solve(int i)
{
    if (i < 3)
    {
        return dp[i];
    }
    if(dp[i] > 0)
    {
        return dp[i];
    }
    int a = Solve(i - 3) + v[i - 1] + v[i];
    int b = Solve(i - 2) + v[i];
    dp[i] = a > b ? a : b;
    return dp[i];
}

int main()
{
    cin >> N;

    v.push_back(0);
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[0] = v[0];
    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    cout << Solve(N) << '\n';
}