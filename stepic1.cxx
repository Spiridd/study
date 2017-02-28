#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	//use string!!!! the following is wrong
	const int SIZE=1000;
	const int SIZE1=20;
	char str[SIZE];
	cin>>str;
	char *p=str;
	short int points=0;
	//counts .?!
	while( !(*p=='\0' && *(p+1)=='\0') )
	{
		cout<<'*'<<*p<<endl;;
		if(*p=='.' || *p=='!' || *p=='?')
		{
			points++;
		}
		p++;
	}
	cout<<points;
	char word[SIZE1];
	int i=0;
	//gets the word
	while(isspace(*p)==0 && i<SIZE1)
	{
		word[i++]=*p++;
	}
	return 0;
}

