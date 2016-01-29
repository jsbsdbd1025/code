//循环移位的问题
//思想来自编程珠玑
/*
假设将abcde循环向前2位（或向后3位） 
可将字符串分为  ab  和  cde 
分别反转得 ba 和 edc
连接起来为baedc
再将整个字符串反转
得cdeab

*/
#include "iostream"
using namespace std;
char ch[10005];
void reverse(int l, int r)
{
	char t;
	while (l < r)
	{
		t = ch[l];
		ch[l] = ch[r];
		ch[r] = t;
		l++;
		r--;
	}
}
int main()
{
	int m;
	int l, r, k;
	scanf("%s", &ch);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &l, &r, &k);
		l--;
		r--;
		k %= (r - l + 1);
		reverse(r - k + 1, r);
		reverse(l, r - k);
		reverse(l, r);
	}
	printf("%s", ch);
	return 0;
}