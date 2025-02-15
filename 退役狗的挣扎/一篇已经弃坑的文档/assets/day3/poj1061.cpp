#include <cstdio>
typedef long long int64;
int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }
void exgcd(int64 a, int64 b, int64 &x, int64 &y) { b == 0 ? (x = 1, y = 0) : (exgcd(b, a % b, y, x), y -= x * (a / b)); }
int main()
{
    int64 s, t, p, q, L;
    scanf("%lld%lld%lld%lld%lld", &s, &t, &p, &q, &L);
    int64 a = (p - q + L) % L, b = L, c = (t - s + L) % L;
    int64 x = 0, y = 0, g = gcd(a, b);
    if (c % g)
        puts("Impossible");
    else
    {
        a /= g, b /= g, c /= g;
        exgcd(a, b, x, y);
        printf("%lld", (((x % b + b) % b) * c) % b);
    }
    return 0;
}