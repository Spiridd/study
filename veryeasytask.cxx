// do N copies using two printers:
// A - x sec/copy
// B - y sec/copy
// what is the minimal time?
#include <iostream>
using namespace std;

int main()
{
	int N, x, y; //copies, x, y
	cin>>N>>x>>y;
	if (x > y)
	{
		x = x + y;
		y = x - y;
		x = x - y;
	}
	int l, r;
	l = 0;
	r = (N-1)*y;
	int mid, now;
	while (l != r )
	{
		mid = (r+l)/2;
		now = mid/x + mid/y;
		if (now < N-1)
			l = mid+1;
		else
			r = mid;
	}
	cout<<"times is "<<x+l<<endl;
	return 0;
}
