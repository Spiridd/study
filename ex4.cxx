#include <iostream>
using namespace std;

long int GetGCD(long int a, long int b);
void SolveDE(long int a, long int b, long int n);

int main()
{
	long int a,b,n;
	cin>>a>>b>>n;
	SolveDE(a,b,n);
	return 0;
}

long int GetGCD(long int a, long int b)
{
	if( a>b )
	{
		if( b==0)
			return a;
		else
			return GetGCD(b,a%b);
	}
	else
	{
		if( a==b )
			return a;
		else
			return GetGCD(b,a);
	}
}
void SolveDE(long int a, long int b, long int n)
{
	if( a<0 )
	{
		a=-a;
		b=-b;
		n=-n;
	}
	short int sign_b=1;
	if( b<0 )
	{
		sign_b=-1;
		b=-b;
	}
	long int a0=a;
	long int b0=b;
	bool flag=true;
	if(a<b)
	{
		flag=false;
		//a<->b
		a=a+b;
		b=a-b;
		a=a-b;
	}
	long int d=GetGCD(a,b);
	if( n%d==0 )
	{
		long int c=n/d;
		a=a/d;
		b=b/d;
		long int x1,y1,x2,y2,q,r;
		//x=x/c, y=y/c -> ax+by=1
		//calculating (x,y)
		if( b==1 )
		{
			x2=1;
			y2=-a+1;
		}
		else
		{
			r=a%b;
			q=a/b;
			a=b;
			b=r;
			x1=1;
			y1=-q;
			if( b==0 )
			{
				x2=1;
				y2=0;
			}
			else
			{
				if( a%b==0 )
				{
					x2=x1;
					y2=y1;
				}
				else
				{
					r=a%b;
					q=a/b;
					x2=-q;
					y2=1-y1*q;
					a=b;
					b=r;
					while(b>0 && b!=1)
					{
						q=a/b;
						r=a%b;
						x2=x1-q*x2;
						y2=y1-q*y2;
						x1=(x1-x2)/q;
						y1=(y1-y2)/q;
						a=b;
						b=r;
					}
				}
			}
		}
		//we have x/c,y/c or x/c,-y/c
		x2*=c;
		y2*=c;
		if( flag==false )
		{
			x2=x2+y2;
			y2=x2-y2;
			x2=x2-y2;
		}
		if( sign_b==-1 )
			y2=-y2;
		while(x2<=0)
		{
			x2+=b0/d;
			if( sign_b==-1 )
				y2+=a0/d;
			else
				y2-=a0/d;
		}
		while( (x2-b0/d)> 0 )
		{
			x2-=b0/d;
			if( sign_b==-1 )
				y2-=a0/d;
			else
				y2+=a0/d;
		}
		cout<<x2<<" "<<y2;
	}
	else
	{
		cout<<"No";
	}
}
