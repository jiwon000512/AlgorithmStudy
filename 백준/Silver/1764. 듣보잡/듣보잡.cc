#include <iostream>
#include <map>

using namespace std;

int N, M;

void Solve()
{
}

int main()
{
    cin >> N >> M;

    string name;
    map<string, bool> m;

    int ansCnt = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> name;
        m.insert({name, false});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> name;

        if (m.find(name) != m.end())
        {
            m.find(name)->second = true;
            ansCnt++;
        }
    }

    cout << ansCnt << '\n';

    for (auto iter : m)
    {
        if (iter.second)
        {
            cout << iter.first << '\n';
        }
    }
}