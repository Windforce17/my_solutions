#include <cstdio>
long long a[501][501], sum, tmp;
int n, x, y;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%I64d", &a[i][j]);
            if (a[i][j] == 0) x = i, y = j;
        }
    tmp = (x + 1) % n;
    for (int i = 0; i < n; i++)
        sum += a[tmp][i];
    tmp = sum;
    for (int i = 0; i < n; i++)
        tmp -= a[x][i];
    if (tmp == 0 && n == 1) tmp = sum = 1;
    a[x][y] = tmp;
    bool flag = tmp > 0;
    for (int i = 0; i < n && flag; i++)
    {
        tmp = 0;
        for (int j = 0; j < n; j++)
            tmp += a[i][j];
        if (tmp != sum) flag = false;
    }
    for (int i = 0; i < n && flag; i++)
    {
        tmp = 0;
        for (int j = 0; j < n; j++)
            tmp += a[j][i];
        if (tmp != sum) flag = false;
    }
    tmp = 0;
    if (flag)
        for (int i = 0; i < n; i++) tmp += a[i][i];
    if (tmp != sum) flag = false;
    tmp = 0;
    if (flag)
        for (int i = 0; i < n; i++) tmp += a[i][n - i - 1];
    if (tmp != sum) flag = false;
    printf("%I64d", flag ? a[x][y] : -1);
    return 0;
}