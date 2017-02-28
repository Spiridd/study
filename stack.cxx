/*
 * Дмитрий Пухов, АиСД-12
 * Задача: одинаково ли число букв 'a', 'b' в введённой строке
 */
#include <iostream>
using namespace std;

class stack
{
	enum {MAXSIZE=1000};
	int body[MAXSIZE];
	int head;
public:
	stack()
	{
		head = 0;
	}
	~stack() {};
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

int main()
{
	//инициализация и ввод данных
	char str[1000];
	//cout<<"Type string like ababab"<<endl;
	cin>>str;
	char *p=str;
	stack st1, st2;
	//заполняем стеки
	while(*p!='\0')
	{
		if(*p=='a')
		{
			st1.push(1);
		}
		else
		{
			st2.push(1);
		}
		p++;
	}
	//пока оба стека непусты, опустошаем
	while( not(st1.empty() || st2.empty()) )
	{
		st1.pop();
		st2.pop();
	}
	//оба стека пусты -> число букв одинаково
	bool res = st1.empty() && st2.empty();
	if(res)
	{
		cout<<"YES"; //equal quantities
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}

