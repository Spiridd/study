//вводится строка из букв A-Z
//вывести частоты и буквы
#include <iostream>
#include <string>
using namespace std;

char GetChar(const string ss, int &start);
int main()
{
	//in
	string str;
	getline(cin,str);
	int length = str.size();
	//develop
	const int num_A = int('A');
	const int num_Z = int('Z');
	const int SIZE = num_Z-num_A+1;
	int freq[SIZE]={0};
	int head=0;
	while( head<length )
	{
		char ch=GetChar(str,head);
		int num_ch=int(ch)-num_A;
		freq[num_ch]++;
	}
	//out
	char abc[SIZE];
	for(int i=0;i<SIZE;i++)
		abc[i]=i+num_A;
	//sort
	bool sorted = false;
	while( !sorted )
	{
		sorted=true;
		for(int i=0; i<SIZE-1;i++)
		{
			if( freq[i]<freq[i+1] )
			{
				sorted=false;
				int x=freq[i];
				freq[i]=freq[i+1];
				freq[i+1]=x;
				x=abc[i];
				abc[i]=abc[i+1];
				abc[i+1]=x;
			}
		}
	}
	for(int i=0; i<SIZE && freq[i]>0; i++)
		cout<<abc[i]<<' '<<freq[i]<<endl;
	return 0;
}

char GetChar(const string ss, int &start)
{
	while(ss[start] == ' ')
		start++;
	return char(ss[start++]);
}
