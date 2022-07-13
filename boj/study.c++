#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, in, sum = 0; 
    stack<int> s;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> in;
        if(in == 0)
        {
            s.pop();
        }
        else
        {
            s.push(in);
        }
    }
    while(!s.empty())
    {
        sum+=s.top();
        s.pop();
    }

    cout << sum << '\n';
}