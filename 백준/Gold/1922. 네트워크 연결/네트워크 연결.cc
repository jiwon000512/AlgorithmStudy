#include <iostream>

using namespace std;

#define MAX_SIZE 1001
#define MAX_LINES 100001

int n, m, i, j, ans;
int pt[MAX_SIZE],start[MAX_LINES],endd[MAX_LINES], cost[MAX_LINES];


void init(int n)
{
    for (int i = 1; i <= n; i++)
        pt[i] = i;
}

int find(int x)
{
    while (pt[x] != x)
        x = pt[x];
    return x;
}

bool inSameSet(int p, int q)
{
    return find(p) == find(q);
}

void _union(int p, int q)
{
    int a = find(p);
    int b = find(q);
    if (a != b)
        pt[b] = a;
}

void swap(int &a, int&b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void sort()
{
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<= m-i; j++)
        {
            if(cost[j-1] > cost[j])
            {
                swap(cost[j-1],cost[j]);
                swap(start[j-1],start[j]);
                swap(endd[j-1],endd[j]);
            }
        }
    }
}

int partition_Hoare(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i = i + 1;
        } while (a[i] < pivot);
        do
        {
            j = j - 1;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(cost[i],cost[j]);
            swap(start[i],start[j]);
            swap(endd[i],endd[j]);
        }
        else
        {
            return j;
        }
    }
}
void quicksort_Hoare(int a[], int low, int high)
{
    if (low >= high)
        return;

    int p = partition_Hoare(a, low, high);
    quicksort_Hoare(a, low, p);
    quicksort_Hoare(a, p + 1, high);
}

void kruscal()
{
    init(n);
    int cnt = 0;
    quicksort_Hoare(cost,0,m-1);
    //sort();

    for(int i=0; i<m; i++)
    {
        if(!inSameSet(start[i],endd[i]))
        {
            _union(start[i],endd[i]);
            ans+=cost[i];
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int k = 0; k < m; k++)
    {
        int v1, v2;
        cin >> start[k] >> endd[k] >> cost[k];
    }
    kruscal();
    cout << ans << '\n';
}