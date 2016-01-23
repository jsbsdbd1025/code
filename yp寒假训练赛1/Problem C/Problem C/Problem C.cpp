#include"stdio.h"
#include"string.h"
int t[200005];
int main()
{
	int T;
	int n, m;
	int p, q;
	int maxn;
	scanf("%d", &T);
	while (T--)
	{
		memset(t, 0, sizeof(t));
		scanf("%d%d", &n, &m);
		maxn = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p);
			t[p] = p;
			if (p > maxn)
				maxn = p;
		}
		p = maxn + 1;
		for (int i = maxn + 1; i > 0; i--)
		{
			if (t[i - 1] == 0)
				p = i - 1;
			else
				t[i - 1] = p;
		}

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &q);
			if (t[q])
				printf("%d\n", t[q]);
			else
				printf("%d\n", q);
		}
	}
    return 0;
}

