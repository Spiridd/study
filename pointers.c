#include <stdio.h>

int main(int argc, char **argv)
{
	int var=5;
	int *c;
	c=&var;
	printf("here is %d\n",*c);
	return 0;
}

