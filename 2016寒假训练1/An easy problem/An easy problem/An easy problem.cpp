#include<stdio.h>
#include<string.h>
#define MAXN 100005
__int64 num[MAXN];
int main()
{
	int T;
	int p = 1;
	int n, m, i;
	int op;
	__int64 ans;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d:\n", p++);
		scanf("%d%d", &n, &m);
		memset(num, 0, sizeof(num));
		ans = 1;
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &op, &num[i]);
			if (op == 1)
			{
				ans = (ans*(num[i] % m)) % m;
			}
			else
			{
				while (ans%num[num[i]])
				{
					ans += m;
				}
				ans = (ans / num[num[i]]) % m;
			}
			printf("%I64d\n", ans);
		}
	}
    return 0;
}

