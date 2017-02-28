//Александр Рубцов
//Сергей Бабичев
//Кормэн перед сном
//Библия Кнута
//Двухпроходный алгоритм

// Stack
//No libraries
//C++ будем использовать как C с классами
/*
 * Абстракция stack
 * Методы: push, pop, empty, create, destroy
 * peak не реализуем (pop+push)
 */
 /*
  * #define max(x,y) x>y?x:y
  * z = max(x++,k--);
  * //we have then
  * z=x++>k--?x++:k--
  * //другой пример (Pascal)
  * #define sqr(x) x*x
  * y = sqr(x+2);
  * //we have then
  * y = x+2*x+2;
 */

//#include <stdio.h>
#include <iostream>
using namespace std;

class stack
{
	//define - bad (look at the above)
	//const - bad
	//const int MAXSIZE=100;
	//2008 and earlier -> error
	//implementation
	enum {MAXSIZE=1000}; //like define
	int body[MAXSIZE];
	int head;
public:
	stack()
	{
		head=0;
	}
	~stack() {}; //для порядка пишем деструктор
	void push(int elem)
	{
		body[head++]=elem;
	}
	int pop()
	{
		return body[--head];
	}
	bool empty()
	{
		return head==0;
	}
};

int gcd_rec(int a, int b)
{
	if(a>b)
	{
		if(b==0)
		{
			return a;
		}
		return gcd(b,a%b);
	}
}
int gcd_iter(int a, int b)
{
	while(b!=0)
	{
		c=b;
		b=a%b;
		a=c;
	}
}

int main()
{
	/*
	stack s;
	for(int i=0; i<50; i++)
	{
		s.push(i*i);
	}
	printf("\n-------\n");
	for(int i=0; i<50; i++)
	{
		printf("%d\n",s.pop());
	}
	*/
	//my solution to 101010101-1
	/*stack bra;
	int x;
	while(cin>>x && x>-1)
	{
		if(x>0)
		{
			bra.push(x);
		}
		else
		{
			if(bra.empty())
			{
				cout<<"error\n";
			}
			else bra.pop();
		}
	}
	if(!bra.empty())
	{
		cout<<"error\n";
	}
	*/
	//we have ababababa
	stack stroka;
	char str[1000];
	cin>>str;
	char *p=&str[0];
	bool error=false;
	while(*p++)
	{
		if(*p=='a')
		{
			stroka.push(1);
		}
		else
		{
			if(stroka.empty())
			{
				error=true; //now work
			}
			else
			{
				stroka.pop();
			}
		}
	}
	if(!stroka.empty())
	{
		error=true;
	}
	if(error)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	//Рубежный контроль: 3 часа решаем задачи
	//Алгоритм Евклида
	// gcd(a,b)=gcd(b,a%b); a>0, b>0, a%b!=0
	// a=q*b+r
	// a div d=0 => r div b=0
	// любую рекурсию можно превратить в итерацию
	//b>a/2 => a%b=a-b
	//b<a/2 => a%b<d/2
	//Д.З. появится 
	//оценить занятие
	return 0;
}

