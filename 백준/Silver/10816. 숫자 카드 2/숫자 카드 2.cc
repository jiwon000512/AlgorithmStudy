#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int in;
        cin >> in;
        cout << upper_bound(arr,arr+n,in) -  lower_bound(arr,arr+n,in) << ' ';
    }
}