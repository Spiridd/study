#include <stdio.h>

int main()
{
	int a[2][3] = { {0, 1, 2},
					{10, 11, 12}};
	printf("a = %d\n",a);
	printf("*a+1 = %d\n",*a+1);
	printf("*a+2 = %d\n",*a+2);
	printf("a+1 = %d\n",a+1);
	printf("&a[1][2] = %d\n",&a[1][2]);
	return 0;
}

