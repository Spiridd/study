#include <stdio.h>
#include <stdlib.h>

char *strcat( char *str1, const char *str2 )
{
	char *cp = str1;
	while( *cp ) cp++;
	while( *cp++ = *str2++ ); 
	return str1;
}
int strlenmy( const char *str )
{
	const char *eos = str;
	while(*eos++);
	return (int) (eos-str-1);
}
char *strcpymy( char *str1, const char *str2 )
{
	char *d = str1;
	while( *d++ = *str2++ );
	return str1;
}

int main()
{
	char src[15] = "hello ";
	char *add="world";
	int len = strlenmy(add);
	printf("Length is %d\n",len);
	strcat(src,add);
	printf("%s\n",src);
	strcpymy(src,add);
	printf("%s\n",src);
	int x=-2;
	int t;
	t=x>0;
	printf("t = %d\n",t);
	int a[]={1,2,3,4,5};
	printf("%d\n",(int)sizeof(a));
	int *vector = calloc(10,sizeof(int));
	//vector[0]=(vector[1]=2)+1;
	int j;
	for(j=0; j<10; j++)
	{
		printf("%d\n",vector[j]);
	}
	printf("-----------------rubbish------------\n");
	int mas[10];
	for(j=0; j<10; j++)
	{
		printf("%d\n",mas[j]);
	}
	static int var;
	printf("var is %d\n",var);
	return 0;
}

