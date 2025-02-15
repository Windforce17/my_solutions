#include <cstdio>
inline int calc(int x)
{
    int ret = 0;
    while (x % 10 == 0) x /= 10;
    if (x % 5 == 0) ret--;
    while (x) x /= 10, ret += 2;
    return ret;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int l, r, minn, ans, tmp;
        scanf("%d%d", &l, &r);
        minn = calc(ans = l);
        while (l < r)
        {
            int p = 1;
            while (l % 10 == 0) l /= 10, p *= 10;
            l = l * p + p;
            if (l <= r && (tmp = calc(l)) < minn) ans = l, minn = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}