//http://blog.csdn.net/popoqqq/article/details/41348131
#include <cstdio>
const int mod = 2007;
int fast_pow(int base, int p)
{
    int ans = 1;
    for (base %= mod; p; base = base * base % mod, p >>= 1)
        if (p & 1)
            ans = ans * base % mod;
    return ans;
}
int main()
{
    int t, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &x);
        printf("%d\n", 4 * x % mod * fast_pow(5, x - 1) % mod);
    }
    return 0;
}