#include <iostream>
using namespace std;

int GetMax2(const int *vec, const int size)
{
	//two or more elements!
	int max = vec[0];
	int max2 = vec[1];
	if( max2 > max )
	{
		max = vec[1];
		max2 = vec[0];
	}
	for(int i=2; i<size; i++)
	{
		if( vec[i]>=max )
		{
			max2 = max;
			max = vec[i];
		}
		else
		{
			if( vec[i]>max2 )
				max2=vec[i];
		}
	}
	return max2;
}

int main()
{
	int N;
	cin>>N;
	int *vector = new int[N];
	for(int i=0; i<N; i++)
		cin>>vector[i];
		
	if( N==1 )
		cout<<vector[0];
	else
	{
		int max2;
		max2 = GetMax2(vector, N);
		cout<<max2;
	}
	delete [] vector;
	return 0;
}
