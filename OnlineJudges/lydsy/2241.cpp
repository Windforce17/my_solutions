#include <cctype>
#include <cstdio>
#include <cstring>
inline void readInt(int &x)
{
    int ch = x = 0;
    while (!isdigit(ch = getchar()))
        ;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
}
int m, n, a[105][105], t[105][105], sum, ans = 0x3f3f3f3f;
void calc(int x, int y)
{
    memcpy(t, a, sizeof(a));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (t[i][j])
            {
                int d = t[i][j];
                if (i + x > m || j + y > n)
                    return;
                else
                    for (int k = i; k < i + x; k++)
                        for (int l = j; l < j + y; l++)
                        {
                            t[k][l] -= d;
                            if (t[k][l] < 0) return;
                        }
            }
    ans = sum / (x * y);
}
int main()
{
    readInt(m), readInt(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            readInt(a[i][j]), sum += a[i][j];
    for (int i = m; i; i--)
        for (int j = n; j; j--)
            if (sum % (i * j) == 0 && sum / (i * j) < ans)
                calc(i, j);
    printf("%d", ans);
    return 0;
}