//doesn't work when gets negative results: - 1 2
// so it can't read negative numbers
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int GetQuantity(int x);
string Calculate(string s1, string s2, string s3);
int GetNumber(const string ss);
string GetString(const string ss, int &start);
bool IfNumber(const string ss);
bool IfOperator(const string ss);
const int ZERO=48;
const int NINE=57;
const int DIVIDE=47;
const int MULTIPLY=42;
const int MINUS=45;
const int PLUS=43;
const char space=' ';
int main()
{
	string str;
	getline(cin,str);
	string s1,s2,s3, change;
	int start=0, after1=0, before1=0;
	while( str.find(space)!=string::npos )
	{
		//get 3 strings
		before1=start;
		s1=GetString(str,start);
		after1=start;
		s2=GetString(str,start);
		s3=GetString(str,start);
		//cout<<"s1,s2,s3: "<<s1<<", "<<s2<<", "<<s3<<endl;
		//check if they can be calculated
		bool b1, b2, b3;
		b1=IfOperator(s1);
		b2=IfNumber(s2);
		b3=IfNumber(s3);
		//cout<<"b1,b2,b3: "<<b1<<", "<<b2<<", "<<b3<<endl;
		if(b1 && b2 && b3)
		{
			//cout<<"YES"<<endl;
			change=Calculate(s1,s2,s3);
			//replace
			if( start>=str.length() )
				str.replace(before1,start-before1,change);
			else
				str.replace(before1,start-before1-1,change);
			start=0;
		}
		else
		{
			start=after1;
		}
		//cout<<"str after: "<<str<<endl;
	}
	cout<<str;
	return 0;
}
int GetNumber(const string ss)
{
	int number=0;
	int sign=1;
	int i0=0;
	int length=ss.length();
	if( (int)ss[0]==MINUS )
	{
		sign=-1;
		i0=1;
	}
	for(int i=i0;i<length;i++)
	{
		number+= ((int)ss[i]-ZERO)*(int)pow(10,length-1-i);
	}
	return number*sign;
}
string GetString(const string ss, int &start)
{
	//gets string from start to SPACE and
	//puts start after SPACE
	int length=ss.length();//-1;
	int start0=start;
	int len=0;
	while(ss[len+start]!=space && (len+start)<length)
		len++;
	start+=len+1;
	if( len==0) //what is it? remove?
		len++;
	return ss.substr(start0,len);
}
bool IfNumber(const string ss)
{
	bool res=true;
	int len=ss.length();
	int i0=0;
	if( (int)ss[0]==MINUS && len>1 )
		i0=1;
	for(int i=i0; i<len; i++)
	{
		if( (int)ss[i]>NINE || (int)ss[i]<ZERO )
		{
			return false;
		}
	}
	return res;
}
bool IfOperator(const string ss)
{
	if(ss.length()!=1)
		return false;
	else
	{
		int a=(int)ss[0];
		if( a==DIVIDE || a==MULTIPLY || a==MINUS || a==PLUS )
			return true;
	}
	return false;
}
string Calculate(string s1, string s2, string s3)
{
	int op1=GetNumber(s2);
	int op2=GetNumber(s3);
	int oper=(int)s1[0];
	int res;
	//do operation
	if( oper==DIVIDE || oper==MULTIPLY )
	{
		if( oper==DIVIDE )
			res=op1/op2;
		else
			res=op1*op2;
	}
	else
	{
		if( oper==PLUS )
			res=op1+op2;
		else
			res=op1-op2;
	}
	//transfrom to string
	//perhaps it should be an individual function
	string repl;
	int i0=0;
	if( res<0 )
	{
		res=-res;
		i0=1;
		repl.push_back((char)MINUS);
	}
	int len=GetQuantity(res)+i0;
	int k;
	for(int i=i0; i<len; i++)
	{
		k=res/(int)pow(10,len-1-i);
		repl.push_back((char)(k+ZERO));
		res-=k*(int)pow(10,len-1-i);
	}
	return repl;
}
int GetQuantity(int x)
{
	x=(int)abs(x);
	int res=1;
	while( (x=x/10)>0 )
		res++;
	return res;
}
