#include <cstdio>
char str[10000];
int a[10000];
int main()
{
    int n;
    scanf("%d\n", &n);
    scanf("%s", str);
    str[n] = 'W';
    int cnt = 0, ite = 0, bcnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (str[i] == 'B')
            bcnt++;
        else if (bcnt != 0)
        {
            a[ite++] = bcnt;
            bcnt = 0;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d ", a[i]);
    return 0;
}