#include <iostream>
#include <string>

using namespace std;

string in;

void Solve()
{
    int ans = 0;
    string num = "";
    bool minus = false;

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '-')
        {
            if (minus)
            {
                ans -= stoi(num);
            }
            else
            {
                ans += stoi(num);
                minus = true;
            }
            num = "";
        }
        else if (in[i] == '+')
        {
            if (minus)
            {
                ans -= stoi(num);
            }
            else
            {
                ans += stoi(num);
            }
            num = "";
        }
        else
        {
            num += in[i];
        }
    }

    if (minus)
    {
        ans -= stoi(num);
    }
    else
    {
        ans += stoi(num);
    }

    cout << ans << '\n';
}

int main()
{
    cin >> in;
    Solve();
}