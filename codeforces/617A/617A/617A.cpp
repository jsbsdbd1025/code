#include"iostream"
#include"algorithm"
using namespace std;
struct P
{
	double x, y;
	double d1, d2;
}p[2005];
bool cmp(P a, P b)
{
	if (a.d2 == b.d2)
		return a.d1 > b.d1;
	return a.d2 > b.d2;

}
int main()
{
	int n;
	double x, y;
	double x1, y1, x2, y2;
	double minn, maxn1, maxn2;
	double d1, d2;
	double ans;
	while (~scanf("%d%lf%lf%lf%lf", &n, &x1, &y1, &x2, &y2))
	{
		
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
			p[i].d1 = (p[i].x - x1)*(p[i].x - x1) + (p[i].y - y1)*(p[i].y - y1);
			p[i].d2 = (p[i].x - x2)*(p[i].x - x2) + (p[i].y - y2)*(p[i].y - y2);
		}
		sort(p, p + n, cmp);
		maxn1 = 0;
		maxn2 = p[0].d2;

		for (int i = 0; i < n; i++)
		{
			ans = maxn1 + maxn2;
			if (max(maxn1, p[i].d1) + p[i+1].d2<ans)
			{
				maxn1 = max(maxn1, p[i].d1);
				maxn2 = p[i+1].d2;
			}
		}
		printf("%.0lf\n", maxn1 + maxn2);
	}
    return 0;
}

