#include <cstdio>
#include <cstring>
#define lowbit(x) ((x) & -(x))
const int maxn = 1 << 15 | 1;
int a[maxn], n, m, level[maxn];
void update(int pos, int x)
{
    for (; pos < maxn; pos += lowbit(pos)) a[pos] += x;
}
int query(int pos)
{
    int ans = 0;
    for (; pos; pos -= lowbit(pos)) ans += a[pos];
    return ans;
}
int main()
{
    scanf("%d", &n);
    memset(level, 0, sizeof(level));
    memset(a, 0, sizeof(a));
    for (int i = 0, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        level[query(++x)]++;
        update(x, 1);
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", level[i]);
    return 0;
}