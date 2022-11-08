#include <stdio.h>
#include <time.h>
int main ()
{
	clock_t mine;
	mine = clock();
	printf("%ld", mine);
	clock_t thistime = clock() - mine;
	printf("%ld\n", thistime);
	thistime = clock() - mine;
	printf("%ld\n", thistime);
	int val;
	scanf("%d", &val);
	thistime = clock() - mine;
	printf("%ld\n", thistime);
	return 0;
}