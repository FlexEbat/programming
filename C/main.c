#include <stdio.h>
int main ()
{
	int n = 0;
	size_t intsize;
	intsize = sizeof (int);
	printf("n = %d, n состоит из %zd байтов; все значения int имеют %zd байтов. \n", n, sizeof n, intsize );
}