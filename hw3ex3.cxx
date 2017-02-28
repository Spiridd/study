// not work
#include <iostream>
using namespace std;

struct Letter
{
	int v;
	int u;
};

int main()
{
	//in
	int N;
	cin>>N;
	//Letter *L = new Letter[N];
	int *v = new int[N];
	int *u = new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>v[i];
		//cin>>L[i].v;
		//L[i].u = i+1;
		u[i]=i+1;
	}
	//cout<<"L"<<L[1].v<<endl;
	//sort
	// try a faster sort!
	bool sorted=false;
	int x;
	while( !sorted )
	{
		sorted=true;
		for(int i=0; i<N-1; i++)
		{
			if( v[i]>v[i+1] )
			{
				sorted=false;
				x=v[i];
				v[i]=v[i+1];
				v[i+1]=x;
				x=u[i];
				u[i]=u[i+1];
				u[i+1]=x;
			}
		}
	}
	int d=v[1]-v[0];
	int first=0;
	for(int i=2; i<N; i++)
	{
		if( v[i]-v[i-1] < d )
		{
			d=v[i]-v[i-1];
			first=i-1;
		}
	}
	cout<<d<<endl;
	u[first]<u[first+1]?
		cout<<u[first]<<" "<<u[first+1]:
		cout<<u[first+1]<<" "<<u[first];
	//delete and finish
	delete [] v;
	delete [] u;
	return 0;
}

