#include <stdio.h>
#define MAX2(a,b) (((a)>(b)) ? (a) : (b))
int main()
{
	int vOne, vTwo;
	int vLargest;

	vOne = 2; vTwo = 8;
	vLargest = MAX2(vOne, vTwo);
	printf("%d is the largest integer among %d and %d\n", vLargest, vOne, vTwo);

	return 0;
}