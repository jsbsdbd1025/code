//ѭ����λ������
//˼�����Ա������
/*
���轫abcdeѭ����ǰ2λ�������3λ�� 
�ɽ��ַ�����Ϊ  ab  ��  cde 
�ֱ�ת�� ba �� edc
��������Ϊbaedc
�ٽ������ַ�����ת
��cdeab

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