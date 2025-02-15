#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
int a[50001], cnt[1000005], ans[200005];
struct query
{
    int id, l, r, b;
} Q[200005];
inline bool operator<(const query &x, const query &y) { return x.b < y.b || (x.b == y.b && x.r < y.r); }
int main()
{
    int n, m, S;
    scanf("%d", &n), S = int(sqrt(n));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        query &q = Q[i];
        scanf("%d%d", &q.l, &q.r);
        q.id = i, q.b = Q[i].l / S;
    }
    std::sort(Q, Q + m);
    for (int i = 0, L = 0, R = 0, tot = 0; i < m; i++)
    {
        int l = Q[i].l, r = Q[i].r;
        while (L < l)
            if (!--cnt[a[L++]]) --tot;
        while (L > l)
            if (!cnt[a[--L]]++) ++tot;
        while (R < r)
            if (!cnt[a[++R]]++) ++tot;
        while (R > r)
            if (!--cnt[a[R--]]) --tot;
        ans[Q[i].id] = tot;
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}