#include <iostream>
#include <map>
using namespace std;
map<int, int> M;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, j, x; i < n; i++)
    {
        cin >> x;
        for (j = 1; j * j < x; j++)
            if (x % j == 0) M[j]++, M[x / j]++;
        if (j * j == x) M[j]++;
    }
    for (map<int, int>::reverse_iterator rite = M.rbegin(); rite != M.rend(); rite++)
        if (rite->second >= k)
        {
            cout << rite->first;
            break;
        }
    return 0;
}
