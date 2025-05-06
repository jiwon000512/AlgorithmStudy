#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    string t;

    cin >> s >> t;

    string reverseT(t.rbegin(), t.rend());

    queue<string> q;
    q.push({s, false});
    while (q.empty() == false)
    {
        string str = q.front();
        q.pop();

        if(str == t)
        {
            cout << '1' << '\n';
            return 0;
        }

        if(t.find(str) != string::npos || reverseT.find(str) != string::npos)
        {
            string temp(str.begin(), str.end());
            str.push_back('A');
            q.push(str);

            temp.push_back('B');
            reverse(temp.begin(), temp.end());
            q.push(temp);
        }
    }

    cout << '0' << '\n';
}
