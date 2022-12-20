#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string poketMon[n + 1];
    map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        cin >> poketMon[i + 1];
        map.insert({poketMon[i + 1], i});
    }

    string in;
    for (int i = 0; i < m; i++)
    {
        int ans;
        cin >> in;
        if (isdigit(in[0]))
        {
            ans = stoi(in);
            cout << poketMon[ans] << '\n';
        }
        else
        {
            ans = map.find(in)->second;
            cout << ans+1 << '\n';
        }
    }
}