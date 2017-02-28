#include <iostream>
using namespace std;
void PrintVector(const int * const * const v, const int size)
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
bool IfInVector(const int * const v, const int size, const int test)
{
	if (size == 1)
	{
		if (*v == test)
			return true;
		else
			return false;
	}
	//size >= 2
	int mid = size/2;
	if (test < v[mid])
		return IfInVector(v,mid,test);
	else
		return IfInVector(v+mid,size-mid,test);
}
bool IfInMatrix (const int * const * const v, const int size, const int test)
{
	//cout<<"call IfInMatrix"<<endl;
	bool IsIn = false;
	int rc = size-1;
	// find real rc
	while (test < v[rc][rc])
	{
		rc--;
		if (rc < 0)
			return false;
	}
	if (rc == size-1 && test != v[rc][rc])
		return false;
	if (test == v[rc][rc])
		return true;
	//search in rc+1 row and rc+1 coloumn
	rc++;
	int len = rc; //to send to IfInVector
	//cout<<"call IfInVector"<<endl;
	//all rows
	for ( ; rc<size; rc++)
	{
		IsIn = IfInVector(v[rc],len,test);
		if (IsIn)
			return true;
	}
	rc = len;
	//make 
	//cout<<"new vector"<<endl;
	int *col = new int[len];
	//all coloumns
	for ( ; rc<size; rc++)
	{
		for (int i=0; i<rc; i++)
			col[i] = v[i][rc];
		IsIn = IfInVector(col,len,test);
		if (IsIn)
		{
			//delete [] col;
			return true;
		}
	}
	//delete [] col;
	return false;
}

int main()
{
	int N;
	cin>>N;
	int **s;
	s = new int * [N];
	for (int i=0; i<N; i++)
	{
		s[i] = new int[N];
	}
	// i - row
	// j - coloumn
	// v[i] = row_i
	for (int i=N-1; i>=0; i--)
		for (int j=0; j<N; j++)
			cin>>s[i][j];
	//cout<<endl<<"Your matrix is"<<endl<<endl;
	//PrintVector(s,N);
	//cout<<"Type x ";
	int x;
	cin>>x;
	if (IfInMatrix(s,N,x))
		cout<<"yes";
	else
		cout<<"no";
	
	//for (int i=0; i<N; i++)
	//{
		//delete [] s[i];
	//}
	//delete [] s;
	return 0;
}
