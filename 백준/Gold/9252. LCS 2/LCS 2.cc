#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a;
string b;

int memo[1001][1001];
vector<char> result;

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
    
    int i = a.size();
	int j = b.size();
	while (i > 0 && j > 0)
	{
		if (memo[i][j] == memo[i - 1][j])
		{
			--i;
		}
		else if (memo[i][j] == memo[i][j - 1])
		{
			--j;
		}
		else
		{
			result.push_back(a[i - 1]);
			--i;
			--j;
		}
	}
    cout << memo[a.size()][b.size()] << endl;
    if(memo[a.size()][b.size()] != 0)
    {
        for(int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i];
        }
    }
}