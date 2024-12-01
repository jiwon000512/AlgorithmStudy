#include <iostream>

using namespace std;

#define MAX 1001

int n;
// r , g , b
int house[MAX][3];
int answer[MAX][3];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }
        answer[i][0] = min(answer[i - 1][1], answer[i - 1][2]) + house[i][0];
        answer[i][1] = min(answer[i - 1][0], answer[i - 1][2]) + house[i][1];
        answer[i][2] = min(answer[i - 1][0], answer[i - 1][1]) + house[i][2];
    }

    cout << min(min(answer[n][0], answer[n][1]), answer[n][2]) << '\n';
}