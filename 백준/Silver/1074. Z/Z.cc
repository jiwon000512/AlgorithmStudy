#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;
int n, r, c;

void traverse(int x, int y, int size)
{ 
    if (y == r && x == c)
    {
        cout << cnt << '\n';
        return;
    }

    if (c >= x && c < x + size && r >= y && r < y+size)
    {
        traverse(x,y,size/2);
        traverse(x+(size/2),y,size/2);
        traverse(x,y+(size/2),size/2);
        traverse(x+(size/2),y+(size/2),size/2);
    }
    else
    {
        cnt+= size*size;
    }
}

int main()
{
    cin >> n >> r >> c;
    int size = pow(2,n);
    traverse(0, 0, size);
}