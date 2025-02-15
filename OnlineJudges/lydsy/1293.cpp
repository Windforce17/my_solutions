#include <algorithm>
#include <cstdio>
inline int min(int a, int b) { return a < b ? a : b; }
struct node
{
    int pos, col;
    bool operator<(const node &R) const { return pos < R.pos || (pos == R.pos && col < R.col); }
} a[1000010];
int cnt[65];
int main()
{
    int n, k, ncnt = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0, ti; i < k; i++)
        for (scanf("%d", &ti); ti; ti--, ncnt++)
            a[ncnt].col = i, scanf("%d", &a[ncnt].pos);
    std::sort(a, a + ncnt);
    int ans = 0x7fffffff, ccnt = 0;
    for (int i = 0, j = 0; i < n && j < n;)
    {
        while (i < n && ccnt < k) ccnt += cnt[a[i++].col]++ == 0;
        while (j < n && ccnt == k) ccnt -= --cnt[a[j++].col] == 0;
        ans = min(ans, a[i - 1].pos - a[j - 1].pos);
    }
    printf("%d", ans);
    return 0;
}