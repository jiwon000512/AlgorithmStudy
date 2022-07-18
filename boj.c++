#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        queue <int> q;
        int m, n, find = 1;
        bool print = false;
        cin >> n >> m;
        int* arr = new int[n];

        for(int j=0; j<n; j++)
        {
            cin >> arr[i];
            q.push(arr[i]);
        }

        while(find != q.size())
        {
            ;
            find ++;
        }
    }
}