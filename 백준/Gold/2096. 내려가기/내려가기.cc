#include <iostream>

using namespace std;

int maxArray[3], minArray[3];
int n;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;

        int tempMaxArray[3] = {0};
        int tempMinArray[3] = {0};
        tempMaxArray[0] = max(maxArray[0], maxArray[1]) + first;
        tempMaxArray[1] = max(max(maxArray[0], maxArray[1]), maxArray[2]) + second;
        tempMaxArray[2] = max(maxArray[1], maxArray[2]) + third;

        tempMinArray[0] = min(minArray[0], minArray[1]) + first;
        tempMinArray[1] = min(min(minArray[0], minArray[1]), minArray[2]) + second;
        tempMinArray[2] = min(minArray[1], minArray[2]) + third;

        for (int i = 0; i < 3; i++)
        {
            maxArray[i] = tempMaxArray[i];
            minArray[i] = tempMinArray[i];
        }
    }

    int maxValue = -1, minValue = -1;
    for (int i = 0; i < 3; i++)
    {
        if (maxValue == -1 || maxValue < maxArray[i])
            maxValue = maxArray[i];
        if (minValue == -1 || minValue > minArray[i])
            minValue = minArray[i];
    }

    cout << maxValue << ' ' << minValue << '\n';
}