#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p = 1;
    bool ans = true;
    stack<int> s;
    queue<char> pr;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (p <= arr[i])
        {
            s.push(p);
            pr.push('+');
            p++;
        }
        if (!s.empty())
        {
            if (s.top() > arr[i])
            {
                ans = false;
                break;
            }
        }

        while (s.top() >= arr[i])
        {
            pr.push('-');
            s.pop();
            if (s.empty())
                break;
        }
    }

    if (ans)
    {
        while (true)
        {
            cout << pr.front() << '\n';
            pr.pop();
            if (pr.empty())
                break;
        }
    }
    else
    {
        cout << "NO\n";
    }
}