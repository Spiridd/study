#include <iostream>
using namespace std;

//передать функтор, который задаёт условие
template <class S, bool order>
class Compare
{
public:
	Compare() {};
	bool operator () (const S ob1, const S ob2)
	{
		if (order)
			return ob1>ob2;
		else
			return ob1<ob2;
	}
};

template <class T, bool order>
void mysort(T * const v, const int size, Compare<T,order> functor)
{
	bool sorted=false;
	while(!sorted)
	{
		sorted=true;
		for(int j=0; j<size-1; j++)
		{
			//if( v[j]>v[j+1] )
			if( functor(v[j],v[j+1]) )
			{
				sorted=false;
				T temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
}
template <class T>
void PrintVector(const T * const v, const int size)
{
	for(int i=0; i<size; i++)
		cout<<v[i]<<' ';
	cout<<endl;
}
int main()
{	
	const short int SIZE=10;
	
	int a[SIZE]={1,5,7,2,-16,9,0,33,-4,5};
	PrintVector(a,SIZE);
	mysort<int> (a,SIZE, Compare<int,false>());
	PrintVector(a,SIZE);
	cout<<endl;
	
	return 0;
}
// все, кроме вектора и односвязного списка
// дека, сет, мап
// чтобы условие проверялось не каждый раз, т.е. было два компаратора
