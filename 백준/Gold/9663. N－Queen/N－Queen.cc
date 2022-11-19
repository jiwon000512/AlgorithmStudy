#include <iostream>

using namespace std;

#define MAX_SIZE 16

int n;
int cases = 0;
int col[MAX_SIZE] = {
    0,
};

bool isPromising(int row)
{
    int k = 0;
    while (k < row)
    {
        if (col[row] == col[k] || abs(col[k] - col[row]) == row - k)
            return false;
        k++;
    }
    return true;
}

void printNqueens(int *col)
{
    for (int i = 0; i < n; i++)
    {
        cout << col[i] + 1 << ' ';
    }
}

void nQueen(int row)
{
    if (row == n)
    {
        cases++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            col[row] = i;
            if (isPromising(row))
                nQueen(row + 1);
        }
    }
}

int main()
{

    cin >> n;
    nQueen(0);
    cout << cases << '\n';

    for (int j = 0; j < n; j++)
    {
        col[j] = 0;
    }
}
