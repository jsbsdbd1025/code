#include<stdio.h>
#include<string.h>
#define M 100005
int parent[M], num[M];
int max;
int find(int x)
{
	int t, k;
	k = x;
	while (k != parent[k])
	{
		k = parent[k];
	}

	while (x != k)
	{
		t = parent[x];
		parent[x] = k;
		x = t;
	}
	return k;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (x>y)
	{
		parent[x] = y;
		num[y] += num[x];
	}
	else
	{
		parent[y] = x;
		num[x] += num[y];
	}
}
int main()
{
	int T;
	int n, a, b, c, i;
	int ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			parent[i] = i;
			num[i] = 1;
		}
		for (i = 1; i<n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (c)
				continue;
			Union(a, b);
		}
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			ans ^= num[parent[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}