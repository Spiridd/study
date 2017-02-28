#include <iostream>
using namespace std;

int GetMax(const int *vec, const int size)
{
	int max=0;
	for(int i=0; i<size; i++)
		if( vec[i]>max)
			max=vec[i];
	return max;
}

int main()
{
	const int SIZE=8;
	int v[SIZE];
	for(int i=0; i<SIZE;i++)
		cin>>v[i];
	int max=0, x;
	while(cin>>x && x>0)
	{
		//check max
		if(x*v[0]>max)
			max=x*v[0];
		//shift to the left
		v[0]=GetMax(v,2);
		for(int i=1;i<SIZE-1;i++)
			v[i]=v[i+1];
		v[SIZE-1]=x;
	}
	cout<<max;
	return 0;
}
