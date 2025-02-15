#include <cstdio>
int a[10010], f[20010], map[1001001], idx;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        if (!map[x])
            map[x] = ++idx;
        a[i] = map[x];
    }
    for (int i = 1, x, y; i <= m; i++)
    {
        char ch;
        scanf("%s%d%d", &ch, &x, &y);
        if (ch == 'R')
        {
            if (!map[y])
                map[y] = ++idx;
            a[x] = map[y];
        }
        else
        {
            int ans = 0;
            for (int j = x; j <= y; j++)
                if (f[a[j]] != i)
                    ans++, f[a[j]] = i;
            printf("%d\n", ans);
        }
    }
    return 0;
}