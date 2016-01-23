//Ë®Ìâ
#include"stdio.h"
#include"string.h"
int main()
{
	int T;
	int n;
	int play1Win, play2Win;
	char p1, p2;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		getchar();
		play1Win = play2Win = 0;
		while (n--)
		{
			scanf("%c%*c%c%*c", &p1, &p2);
			if (p1 == 'R'&&p2 == 'S') play1Win++;
			else if (p1 == 'S'&&p2 == 'R') play2Win++;
			else if (p1 == 'S'&&p2 == 'P') play1Win++;
			else if (p1 == 'P'&&p2 == 'S') play2Win++;
			else if (p1 == 'P'&&p2 == 'R') play1Win++;
			else if (p1 == 'R'&&p2 == 'P') play2Win++;
		}
		if (play1Win > play2Win)
		{
			printf("Player 1\n");
		}
		else if (play1Win < play2Win)
		{
			printf("Player 2\n");
		}
		else
		{
			printf("TIE\n");
		}
	}
    return 0;
}

