#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<string> solve(int n)
{
    if (n == 3)
    {
        return {"  *  ", " * * ", "*****"};
    }

    vector<string> prev = solve(n / 2);
    vector<string> res;

    for (string s : prev)
        res.push_back(string(n / 2, ' ') + s + string(n / 2, ' '));

    // 아래쪽 삼각형
    for (string s : prev)
        res.push_back(s + " " + s);

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> result = solve(n);
    for (string s : result)
        cout << s << '\n';
}
