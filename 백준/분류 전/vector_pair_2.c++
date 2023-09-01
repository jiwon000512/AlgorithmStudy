#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> in;
    vector<pair<int, int>> xy;

    for (int i = 0; i < n; i++)
    {
        cin >> in.first >> in.second;
        xy.push_back(in);
    }

    stable_sort(xy.begin(), xy.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << xy[i].first << ' ' << xy[i].second << '\n';
    }
}