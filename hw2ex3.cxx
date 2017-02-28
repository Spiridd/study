#include <iostream>
using namespace std;

int main()
{
	//инициализация
	int N1, N2;
	cin>>N1>>N2;
	int *v1=new int[N1];
	int *v2=new int[N2];
	int i,j;
	for(i=0; i<N1; i++)
		cin>>v1[i];
	for(j=0; j<N2; j++)
		cin>>v2[j];
	//решение
	int count=0, j0=0;
	for(i=0; i<N1; i++)
	{
		for(j=j0; v1[i]>=v2[j] && j<N2; j++)
		{
			if( v1[i]==v2[j] )
			{
				count++;
				j0=j+1;
				j=N2;
			}
		}
	}
	cout<<count;
	delete []v1;
	delete []v2;
	return 0;
}

