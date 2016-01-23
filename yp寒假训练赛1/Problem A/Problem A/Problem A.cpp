#include"iostream"
#include"algorithm"
#include"map"
using namespace std;
int temp[100005];
//存小数点后第几位的值
int main()
{
	int n, m;
	int count;
	int flag;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 1 && m == 1)
		{
			printf("0\n");
			continue;
		}
		map<int, int> vis;
		int t = 1;
		int k = 1;
		flag = 0;
		count = 0;
		while (!vis[k]&&count<m)
		{
			if (k == 0)
			{
				flag = 1;
				break;
			}
			vis[k] = count+1;
			t = k * 10 / n;
			temp[count++] = t;
			k = (k * 10) % n;
		}
		if (flag)//出现0的情况后面都是0
			printf("0\n");
		else if (m == count)//直接找到结果
			printf("%d\n", temp[m-1]);
		else//存在循环节，处理掉刚开始不是循环节后面开始循环节的情况1/6 = 0.16666...
		{
			count = count - vis[k] + 1;
			printf("%d\n", temp[(m - vis[k]) % count + (vis[k] - 1)]);
		}
	}
    return 0;
}

