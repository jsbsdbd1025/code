#include"iostream"
#include"algorithm"
using namespace std;
int m[1005];//存是否存在某个Ai
int main()
{
	int n;
	int a[105];
	int i, j;
	int flag;
	while (scanf("%d", &n) != EOF)
	{
		memset(m, 0, sizeof(m));
		for (i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
			m[a[i]]++;
		}
		sort(a, a + n);//方便a[i]-a[j]>=0
		flag = 0;
		for (i = 1; i < n; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (m[a[i] - a[j]])
				{
					if ((a[i] - a[j] == a[j] && m[a[j]] == 1) || (a[i] - a[j] == a[i] && m[a[i]] == 1))
						continue;
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}

