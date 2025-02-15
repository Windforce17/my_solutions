#include <cstdio>
#include <cstring>
int n, ans;
int next[2010 * 2010], to[2010 * 2010], head[2010], idx;
char buf[2010];
bool vis[2010];
void addEdge(int f, int t)
{
    idx++;
    next[idx] = head[f];
    head[f] = idx;
    to[idx] = t;
}
void dfs(int x)
{
    ans++;
    vis[x] = true;
    for (int cur = head[x]; cur; cur = next[cur])
        if (!vis[to[cur]])
            dfs(to[cur]);
}
int main()
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fgets(buf, 2010, stdin);
        for (int j = 0; j < n; j++)
            if (buf[j] == '1')
                addEdge(i + 1, j + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }
    printf("%d", ans);
    return 0;
}