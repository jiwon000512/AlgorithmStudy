#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<string> dq;
bool isReverse = false;

void swap()
{
    isReverse = !isReverse;
}

bool discard()
{
    if (dq.empty())
    {
        cout << "error" << '\n';
        return false;
    }

    if (isReverse)
        dq.pop_back();
    else
        dq.pop_front();

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, n;
    string p, a;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        isReverse = false;
        dq.clear();
        cin >> p;
        cin >> n;
        cin >> a;

        int j = 0;
        string tmp = "";
        while (j < a.length())
        {
            if(isdigit(a[j]))
                tmp += a[j];
            else
            {
                if(tmp.compare("") != 0)
                {
                    dq.push_back(tmp);
                    tmp = "";
                }
                
            }
            j++;
        }
        bool isBabo = false;
        for (j = 0; j < p.length(); j++)
        {
            if (p[j] == 'D')
            {
                if (!discard())
                {
                    isBabo = true;
                    break;
                }
                    
            }
            else if (p[j] == 'R')
            {
                swap();
            }
        }

        if (dq.empty())
        {
            if(!isBabo)
                cout << "[]" << '\n';
            continue;
        }
            

        string out = "[";
        if (isReverse)
        {
            for (int j = (int)dq.size() - 1; j >= 0; j--)
            {
                out += dq[j] + ',';
            }
        }
        else
        {
            for (int j = 0; j < (int)dq.size(); j++)
            {
                out += dq[j] + ',';
            }
        }
        out.pop_back();
        out += ']';

        cout << out << '\n';
    }
}