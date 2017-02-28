#include <iostream>
using namespace std;
int GetUnimodMax(const int * const s, const int size)
{
	//Get Max from unimodal vector: a1 < a2 < ... < ak > ak-1 > ... > an
	// algorithm is recursive
	// complexity is hoped to be O(log size)
	if (size == 3)
	{
		if (s[1] > s[0] && s[1] > s[2])
			return s[1];
		else
			return -1;
	}
	int mid = size/2;
	if (s[mid] > s[mid-1])
	{
		if (s[mid] < s[mid+1])
			return GetUnimodMax(s+mid-1,size-mid+1);
		else
			return s[mid];
	}
	else
	{
		return GetUnimodMax(s,size-mid+1);
	}
}

int main()
{
	int N;
	cin>>N;
	int *v = new int[N];
	for(int i=0; i<N; i++)
		cin>>v[i];
	cout<<GetUnimodMax(v,N);
	delete [] v;
	return 0;
}
