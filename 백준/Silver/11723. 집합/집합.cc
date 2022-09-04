#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    int arr[21] = {0,};

    for (int i = 0; i < m; i++)
    {

        string order;
        cin >> order;

        if (order == "add")
        {
            int in;
            cin >> in;
            if(arr[in] == 0)
            {
                arr[in] = 1;
            }
        }
        else if (order == "remove")
        {
            int out;
            cin >> out;
            if(arr[out] == 1)
            {
                arr[out] = 0;
            }
        }
        else if (order == "check")
        {
            int test;
            cin >> test;
            if (arr[test] == 0)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << 1 << '\n';
            }
        }
        else if (order == "toggle")
        {
            int test;
            cin >> test;

            if (arr[test] == 0)
            {
                arr[test] = 1;
            }
            else
            {
                arr[test] = 0;
            }
        }
        else if (order == "all")
        {
            for (int i = 0; i < 21; i++)
            {
                arr[i] = 1;
            }
        }
        else if (order.find("empty") == 0)
        {
            for (int i = 0; i < 21; i++)
            {
                arr[i] = 0;
            }
        }
    }
}