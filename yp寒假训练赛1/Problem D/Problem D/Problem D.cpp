#include"iostream"
#include"algorithm"
#include"map"
using namespace std;
int vis[10];
int ans[100005];
int COUNT = 0;

void DFS(int num, int cur)
{
	for (int i = 0; i <= 9; i++)
	{
		if (!vis[i] && cur < 4)
		{
			vis[i] = 1;
			ans[COUNT++] = num * 10 + i;
			DFS(num * 10 + i, cur + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	int T;
	int l, r;
	int out;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= 9; i++)
	{
		vis[i] = 1;
		ans[COUNT++] = i;;
		DFS(i, 0);
		vis[i] = 0;
	}
	sort(ans, ans + COUNT);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &l, &r);
		out = 0;
		for (int i = 0; i < COUNT; i++)
		{
			if (ans[i] >= l&&ans[i] <= r)
			{
				out++;
			}
			if (ans[i] > r)
				break;
		}
		printf("%d\n", out);
	}
    return 0;
}

