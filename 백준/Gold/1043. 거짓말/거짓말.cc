#include <iostream>
#include <vector>

using namespace std;

int N, M, answer;
vector<vector<int>> v;
int p[51];
vector<int> truth;

int findParent(int x)
{
    if (p[x] == x)
        return x;
    else
        return findParent(p[x]);
}

void unionTarget(int a, int b)
{
    int rootA = findParent(a);
    int rootB = findParent(b);
    p[rootA] = rootB;
}

int main()
{
    cin >> N >> M;
    int count;
    cin >> count;

    while (count--)
    {
        int n;
        cin >> n;
        truth.push_back(n);
    }

    for (int i = 1; i <= N; i++)
        p[i] = i;

    int answer = M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            int in;
            cin >> in;
            tmp.push_back(in);
        }
        v.push_back(tmp);

        if (n == 0)
            continue;
        for (int k = 1; k < tmp.size(); k++)
            unionTarget(tmp[0], tmp[k]);
    }

    for (int i = 0; i < v.size(); i++)
    {
        bool canLie = false;
        for (int j = 0; j < v[i].size(); j++)
        {
            for (int k = 0; k < truth.size(); k++)
            {
                if (findParent(v[i][j]) == findParent(truth[k]))
                {
                    canLie = true;
                    break;
                }
            }
        }
        if (canLie)
            answer--;
    }
    cout << answer << '\n';
}