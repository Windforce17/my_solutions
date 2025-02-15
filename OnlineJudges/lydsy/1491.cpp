#include <cstdio>
#include <cstring>
int G[101][101], n, m;
long long a[101][101];
double ans[101];
int main()
{
    memset(G, 0x3f3f3f3f, sizeof(G));
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y, z; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        G[x][y] = G[y][x] = z;
        a[x][y] = a[y][x] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (G[i][j] > G[i][k] + G[k][j]) G[i][j] = G[i][k] + G[k][j], a[i][j] = 0;
                if (G[i][j] == G[i][k] + G[k][j]) a[i][j] += a[i][k] * a[k][j];
            }
    for (int i = 1; i <= n; i++) a[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (G[i][j] == G[i][k] + G[k][j] && a[i][j] > 0)
                    ans[k] += 1.0 * a[i][k] * a[k][j] / a[i][j];
    for (int i = 1; i <= n; i++) printf("%.3lf\n", ans[i]);
    return 0;
}