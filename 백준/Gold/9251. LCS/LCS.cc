#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a;
string b;

int memo[1001][1001];

int main()
{
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                memo[i + 1][j + 1] = memo[i][j] + 1;
            }
            else
            {
                memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);
            }
        }
    }

    cout << memo[a.size()][b.size()] << endl;
}