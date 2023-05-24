#include <stdio.h>


int main()
{
	unsigned int a = -1;
	unsigned int b = 2;

	printf("%d\t%d\n", a, b);
	if ((int)a > 0 || b > 0)
		printf("hello\n");
	if ((int)a >= 0 && b >= 0)
		printf("hello2\n");
	if ((int)a >= 0 || (int)b >= 0)
		printf("hello3\n");
	if ((int)a != '\0' || b >= '\0')
		printf("hello4\n");

	if ((a != '\0' && b != '\0') && (a >= 0 && b >= 0))
		printf("hello5\n");
}
