//#include <iostream>
#include <stdio.h>
//using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	//cin>>N;
	long long d1=0,d3=0,d5=0,d15=0,c15=0;
	long long x;
	for(int i=0; i<N; i++)
	{
		scanf("%lld",&x);
		//cin>>x;
		if( x%15 == 0 )
		{
			if( x>d15 )
			{
				c15=d15;
				d15=x;
			}
			else if( x>c15)
			{
				c15=x;
			}
		}
		else
		{
			if( x%5==0 )
			{
				if( x>d5 )
					d5=x;
			}
			else
			{
				if( x%3==0 )
				{
					if( x>d3 )
						d3=x;
				}
				else
				{
					if( x>d1 )
						d1=x;
				}
			}
		}
	}
	//cout<<d1<<" "<<d3<<" "<<d5<<" "<<d15<<" "<<c15<<endl;
	//printf("%lld %lld %lld %lld  %lld\n",d1,d3,d5,d15,c15);
	//we have d1,d3,d15,c15..
	long long max=d15*c15;
	if( d15*d1>max )
		max=d15*d1;
	if( d15*d3>max )
		max=d15*d3;
	if( d15*d5>max )
		max=d15*d5;
	if( d3*d5>max)
		max=d3*d5;
	printf("%lld",max);
	//cout<<max;
	return 0;
}

