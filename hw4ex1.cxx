#include <iostream>
#include <cstdlib>
using namespace std;

int GetMax(const int * const v, const int size)
{
	int max=v[0];
	for (int i=1; i<size; i++)
		max = v[i]>max? v[i] : max;
	return max;
}
int GetCuts (const int * const v, const int size, const int onecut)
{
	int sum=0;
	for(int i=0; i < size; i++)
		sum += v[i]/onecut;
	return sum;
}
int GetMaxLength (int * const v, const int size, const int required)
{
	int low = 0, high = GetMax(v,size);
	int mid;
	int now, next;
	while (low != high)
	{
		mid = (high+low)/2;
		if (mid == 0)
			return -1;
		now = GetCuts (v,size,mid);
		if (now >= required)
		{
			next = GetCuts (v,size,mid+1);
			if (next < required)
				return mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return low;
}

int main()
{
	// input
	int N, K;
	cin>>N>>K;
	int *s = new int[N];
	for(int i=0; i<N; i++)
		cin>>s[i];
	// look for max length
	cout<<GetMaxLength(s,N,K);
	// finish
	delete [] s;
	return 0;
}
