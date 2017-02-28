#include <stdio.h>

int main()
{
	long long N;
	scanf("%lld",&N);
	long long x=0,x0;
	long long xmax=N;
	long long k;
	//xmax
	for(x=0; x*x<N; x++) {}
	xmax=x-1;
	//printf("%lld\n",xmax);
	for(x=1; xmax*xmax+x*x<N;x++) {}
	x=x-1;
	k=xmax*xmax+2*x+2;
	//new round
	xmax=xmax-1;
	x0=x+1;
	short int go=1;
	while(go==1)
	{
		for(x=x0; xmax*xmax+x*x<N; x++) {}
		if( x>xmax )
			go=0;
		else
		{
			if( x==xmax)
				k=k-1;
			else
				k=k-(xmax-x)*2-
				1;
			xmax=xmax-1;
			x0=x;
		}
	}
	printf("%lld",k);
	return 0;
}

