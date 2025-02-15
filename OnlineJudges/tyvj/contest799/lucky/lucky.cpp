#include <algorithm>
#include <cstdio>
using namespace std;
int n, k, ans = 0;
int a[1000];
int arr[1000];
bool used[1000];
inline bool check(int x)
{
    int p;
    while (x)
    {
        p = x % 10;
        if (p != 4 && p != 7) return false;
        x /= 10;
    }
    return true;
}
void dfs(int step, int last)
{
    if (step == k)
    {
        int flag = 1;
        for (int i = 0; i < k - 1 && flag; i++)
            if ((arr[i] == arr[i + 1]) && check(arr[i]))
                flag = 0;
        ans += flag;
    }
    else
        for (int i = last + 1; i < n; i++)
            if (!used[i])
            {
                used[i] = true;
                arr[step] = a[i];
                dfs(step + 1, i);
                used[i] = false;
            }
}
int main()
{
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    dfs(0, -1);
    printf("%d", ans);
    return 0;
}