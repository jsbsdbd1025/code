#include "stdio.h"
int array[12] = { 13,19,9,5,12,8,7,4,21,2,6,11 };

void swap(int x, int y)
{
	int t;
	t = array[x];
	array[x] = array[y];
	array[y] = t;
	/*array[x] = array[x] + array[y];
	array[y] = array[x] - array[y];
	array[x] = array[x] - array[y];*/
}
int partition(int l, int r)
{
	int stand = array[r];
	int i = r;

	for (int j = l; j < r; j++)
	{
		while (array[j] >= stand && i > j)
		{
			i--;
			swap(i, j);
		}
	}
	swap(i, r);
	return i;
}
void quickSort(int l, int r)
{
	if (l >= r)
		return ;
	int q = partition(l, r);
	quickSort(l, q - 1);
	quickSort(q + 1, r);
}
int main()
{
	quickSort(0,11);

	for (int i = 0; i < 12; i++)
	{
		printf("%d ", array[i]);
	}
	while (1);
    return 0;
}

