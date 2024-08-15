#include <iostream>
#include <map>

using namespace std;

int board[101];
map<int, int> m;

void solve(int num, int count)
{
    if (m.find(num) != m.end())
    {
        solve(m[num], count);
        return;
    }

    if (board[num] != 0 && board[num] <= count)
        return;

    board[num] = count;
    
    for (int i = 1; i <= 6; i++)
    {
        if (num + i > 100)
            continue;

        solve(num + i, count + 1);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int key, value;
    for (int i = 0; i < N; i++)
    {
        cin >> key >> value;
        m.insert({key, value});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> key >> value;
        m.insert({key, value});
    }

    for (int i = 1; i <= 6; i++)
    {
        solve(1 + i, 1);
    }

    cout << board[100] << '\n';
}