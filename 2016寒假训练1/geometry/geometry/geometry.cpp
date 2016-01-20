#include"stdio.h"
#include"math.h"
int main()
{
	int T;
	double x, y;
	double p;
	double dis;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%lf", &x, &y);
		p = x + y;
		dis = pow(2 * x*x, 0.5)*pow(2 * y*y, 0.5);
		printf("%.0lf\n", dis);

	}
    return 0;
}

