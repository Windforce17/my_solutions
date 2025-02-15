#include <cstdio>
#include <cstring>
inline int min(int a, int b) { return a < b ? a : b; }
const int maxn = 310, maxm = maxn * maxn * 2, inf = 0x3f3f3f3f;
int head[maxn], to[maxm], cap[maxm], next[maxm], ecnt;
int dis[maxn], num[maxn], fa[maxn], que[maxn], cur[maxn], cnt;
inline void addEdge_impl_(int f, int t, int c)
{
    next[ecnt] = head[f];
    head[f] = ecnt;
    to[ecnt] = t;
    cap[ecnt] = c;
    ecnt++;
}
inline void addEdge(int f, int t, int c)
{
    addEdge_impl_(f, t, c);
    addEdge_impl_(t, f, 0);
}
int ISAP(int s, int e)
{
    int h = 0, t = 0, x, flow = 0;
    for (int i = 0; i <= cnt; i++) dis[i] = cnt;
    dis[que[t++] = e] = 0;
    while (h != t)
        for (int i = head[x = que[h++]]; ~i; i = next[i])
            if (cap[i ^ 1] > 0 && dis[to[i]] > dis[x] + 1)
                dis[que[t++] = to[i]] = dis[x] + 1;
    memset(num, 0, sizeof(num));
    for (int i = 0; i <= cnt; i++) num[dis[i]]++, cur[i] = head[i];
    x = s;
    while (dis[s] < cnt)
    {
        if (x == e)
        {
            int curFlow = inf;
            for (x = e; x != s; x = to[fa[x] ^ 1]) curFlow = min(curFlow, cap[fa[x]]);
            for (x = e; x != s; x = to[fa[x] ^ 1]) cap[fa[x]] -= curFlow, cap[fa[x] ^ 1] += curFlow;
            flow += curFlow, x = s;
        }
        bool needRetreat = true;
        for (int i = cur[x]; needRetreat && ~i; i = next[i])
            if (cap[i] > 0 && dis[x] == dis[to[i]] + 1)
                needRetreat = false, cur[x] = i, fa[x = to[i]] = i;
        if (needRetreat)
        {
            int mn = cnt - 1;
            for (int i = head[x]; ~i; i = next[i])
                if (cap[i]) mn = min(mn, dis[to[i]]);
            if (--num[dis[x]] == 0) break;
            ++num[dis[x] = mn + 1];
            cur[x] = head[x];
            if (x != s) x = to[fa[x] ^ 1];
        }
    }
    return flow;
}
int main()
{
    memset(head, -1, sizeof(head));
    int n, m;
    scanf("%d%d", &n, &m);
    cnt = n + 2;
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        if (x)
            addEdge(0, i, 1);
        else
            addEdge(i, n + 1, 1);
    }
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        addEdge_impl_(x, y, 1);
        addEdge_impl_(y, x, 1);
    }
    printf("%d", ISAP(0, n + 1));
    return 0;
}