//N points (x,y)
//find a triangle with max square
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//input
	int N;
	cin>>N;
	int *x=new int[N];
	int *y=new int[N];
	int i=0;
	float xx,yy;
	for(i=0;i<N;i++)
	{
		cin>>xx>>yy;
		x[i]=(int)100*xx;
		y[i]=(int)100*yy;
	}
	//when cout, divide square by 100^2!
	//seek max y
	int ymax=0;
	int it[3]; //indexes of points
	for(i=0;i<N;i++)
	{
		if( abs(y[i])>ymax )
		{
			ymax=y[i];
			it[2]=i;
		}
	}
	//seek first corresponding Ox point 
	for(i=0;i<N;i++)
	{
		if( y[i]==0 && x[i]*x[it[2]]>0 )
		{
			it[0]=i;
			it[1]=i; //then we will find correct index
			i=N;
		}
	}
	//seek second corresponding Ox point
	//distance first-second must be max
	for(i=it[0]+1;i<N;i++)
	{
		if( y[i]==0 && x[i]*x[it[2]]>0 && abs(x[it[0]]-x[i])>abs(x[it[0]]-x[it[1]]) )
		{
			it[1]=i;
		}
	}
	float s=abs(y[it[2]])*abs(x[it[0]]-x[it[1]])/100/100/2;
	//seek max y: x*x[it[2]]<0
	xx=x[it[2]];
	ymax=0;
	for(i=0;i<N;i++)
	{
		if( abs(y[i])>ymax && x[i]*xx<0 )
		{
			ymax=y[i];
			it[2]=i;
		}
	}
	bool flag=false;
	if( xx==x[it[2]] )
		cout<<s;
	else
	{
		for(i=0;i<N;i++)
		{
			if( y[i]==0 && x[i]*x[it[2]]>0 )
			{
				flag=true;
				it[0]=i;
				it[1]=i;
				i=N;
			}
		}
		for(i=it[0]+1;i<N;i++)
		{
			if( y[i]==0 && x[i]*x[it[2]]>0 && abs(x[it[0]]-x[i])>abs(x[it[0]]-x[it[1]]) )
			{
				it[1]=i;
			}
		}
		if( it[0]==it[1] || !flag )
			cout<<s;
		else
		{
			float s1=abs(y[it[2]])*abs(x[it[0]]-x[it[1]])/100/100/2;
			if(s1>s)
				cout<<s1;
			else
				cout<<s;
		}
	}
	return 0;
}
