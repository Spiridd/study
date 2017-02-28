#include <iostream>
using namespace std;

void PutGrayCodeRev(int k, int num, int *key);
void PutGrayCode(int k, int num, int *key);

int main()
{
	int N;
	cin>>N;
	int *code = new int[N];
	PutGrayCode(0,N,code);
	delete code;
	return 0;
}

void PutGrayCode(int k, int num, int *key)
{
	if( k==num )
	{
		for(int i=0; i<num; i++)
			cout<<key[i];
		cout<<endl;
	}
	else
	{
		key[k]=0;
		PutGrayCode(k+1, num, key);
		key[k]=1;
		PutGrayCodeRev(k+1, num, key);
	}
}
void PutGrayCodeRev(int k, int num, int *key)
{
	if( k==num )
	{
		for(int i=0; i<num; i++)
			cout<<key[i];
		cout<<endl;
	}
	else
	{
		key[k]=1;
		PutGrayCode(k+1, num, key);
		key[k]=0;
		PutGrayCodeRev(k+1, num, key);
	}
}

