
#include <stdio.h>
#define MAX 10000
int record[MAX];
int work(int m, int n)
{
	int temp;
	int a;
	temp = n - m + 1;
	if (temp < 10000 && record[temp] != -1)
		return record[temp];
	else if ( temp < 3)
		return 0;
	else if ( temp == 3)
		return 1;
	else {
		 a = work(m, m + temp / 2 - 1) + work(m + temp / 2, n);
		if ( temp < 10000 )
			record[temp] = a;
		return a;
	}
}
int main()
{
    int i,m;
	for ( i = 0; i < MAX; i++)
		record[i] = -1;
	while ( scanf( "%d", &m ) && m != 0 )
		printf("%d\n", work( 1, m ) );
	return 0;
}