#include <stdio.h>
#include <stdlib.h>
void predict_killer()
{
	char killer = '0';
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'B') + (killer == 'C') + (killer != 'D') == 3)
		{
	    	printf("Ð×ÊÖÊÇ: %c", killer);
			break;
		}
	}
}
int main()
{
	predict_killer();
	system("pause");
	return 0;
}