#include <iostream>
#include <cstdlib>
using namespace std;

int FindMin(const int * const v, const int size)
{
	int min=0;
	for(int i=1; i<size; i++)
		if(v[i] < v[min])
			min=i;
	return min;
}

void PrintVector(const int * const v, const int size)
{
	for(int i=0; i<size; i++)
		cout<<v[i]<<' ';
	cout<<endl;
}
void SortInsert(int * const v, const int size)
{
	int x, i;
	for(i=0; i<size-1;i++)
		if( v[i]>v[i+1] )
		{
			x=v[i];
			v[i]=v[i+1];
			v[i+1]=x;
		}
	int j, tmp;
	for(i=1; i<size-1; i++)
	{
		tmp=v[i];
		j=i;
		while( tmp<v[j-1] )
		{
			v[j]=v[j-1];
			j--;
			if( j==0 )
				break;
		}
		v[j]=tmp;
	}
}
void SortShell(int *v, const int size)
{
	int h;
	for (h=1; h<size/9; h=3*h+1)
		;
	for ( ; h>0; h=h/3)
	{
		for (int i=h; i<size; i++)
		{
			int j=i;
			int tmp = v[j];
			while (j >= h && tmp < v[j-h])
			{
				v[j]=v[j-h];
				j=j-h;
			}
			v[j]=tmp;
		}
	}
}
void SortChoice(int *v, const int size)
{
	int min;
	for(int i=0; i<size-1; i++)
	{
		min=FindMin(v+1+i,size-1-i)+1+i;
		if (v[min] < v[i])
		{
			int tmp=v[min];
			v[min]=v[i];
			v[i]=tmp;
		}
	}
}
int GetStat(const int * const v, const int size, const int k)
{
	// doesn't free memory
	int *S = new int[3*size];
	if (size == 1)
		return *v;
	int pivot = v[rand()%size];
	int size_l=0;
	int size_v=0;
	int size_r=0;
	for (int i=0; i<size; i++)
	{
		if (v[i] < pivot)
		{
			S[size_l]=v[i];
			size_l++;
		}
		else if (v[i] > pivot)
		{
			S[2*size + size_r]=v[i];
			size_r++;
		}
		else
		{
			S[size + size_v]=v[i];
			size_v++;
		}
	}
	if (size_v == size) // vector with equal elements
		return v[0];
	if (k <= size_l)
		return GetStat(S,size_l,k);
	else if (k > size_l+size_v)
		return GetStat(S+2*size,size_r,k-size_l-size_v);
	else
		return GetStat(S+size,size_v,k-size_l);
}
void SortPlain (int a[], int low, int high)
{
	//for two elements or one element
	if (high-low < 2)
	{
		if (a[high] < a[low] )
		{
			int x=a[high];
			a[high]=a[low];
			a[low]=x;
		}
	}
	else cout<<"ERROR"<<endl;
} 
void Merge(int a[], int low, int mid, int high)
{
	//dynamic memory implementation
	
	//new vectors to merge
	int *ll = new int[mid-low+1];
	int *rr = new int[high-mid];
	for (int i=0; i<mid-low+1; i++)
		ll[i] = a[low+i];
	for (int i=0; i<high-mid; i++)
		rr[i] = a[mid+1+i];
	//vectors are filled in
	int left=low;
	int right=mid+1;
	int count=low;
	while (left <= mid && right <= high)
	{
		if (ll[left-low] > rr[right-mid-1])
		{
			a[count]=rr[right-mid-1];
			count++;
			right++;
		}
		else
		{
			a[count]=ll[left-low];
			count++;
			left++;
		}
	}
	// one of two
	while (right <= high)
	{
		a[count] = rr[right-mid-1];
		count++;
		right++;
	}
	while (left <= mid)
	{
		a[count] = ll[left-low];
		count++;
		left++;
	}
	delete [] ll;
	delete [] rr;
}
void SortMerge(int a[], int low, int high)
{
	//high is size-1 when low is zero!!!
	if( (high-low+1) < 3 )
	{
		SortPlain(a,low,high);
	}
	else
	{
		int mid=(high+low)/2;
		SortMerge(a,low,mid);
		SortMerge(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
void SortQuick(int * const a, const int size)
{
	// stable sorting
	// dynamic memory implementation
	if (size <= 5)
	{
		SortInsert(a, size);
		return;
	}
	
	int pivot = a[rand()%size];
	cout<<"pivot = "<<pivot<<endl;
	int *left = new int[size];
	static int *right = new int[size];
	static int size_l = 0, size_r = 0;
	//cout<<"new memory; size = "<<size<<endl;
	for (int i=0; i<size; i++)
	{
		if (a[i] > pivot)
		{
			right[size_r] = a[i];
			size_r++;
		}
		else
		{
			left[size_l] = a[i];
			size_l++;
		}
	}
	for (int i=0; i<size_l; i++)
		a[i] = left[i];
	for (int i=0; i<size_r; i++)
		a[i+size_l] = right[i];
		
	SortQuick(a,size_l);
	SortQuick(a+size_l,size_r);
	cout<<"END"<<endl;
	PrintVector(a,size);
	cout<<endl;
	delete [] left;
	delete [] right;
}
void SortQuickUnstable (int * const a, const int size)
{
	//fucking wrong algorithm
	if (size <= 5)
	{
		cout<<"insert for ";
		PrintVector(a,size);
		SortInsert(a,size);
		return;
	}
	int pivot = rand()%size;
	int piv = a[pivot];
	cout<<"pivot = "<<pivot<<endl;
	int tmp;
	int low = 0, high = size-1;
	int i=low, j=high;
	while (i < j)
	{
		while (a[i] < piv) i++;
		while (a[j] > piv) j--;
		if (i < j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	cout<<"i,j = "<<i<<j<<endl;
	PrintVector(a,size);
	SortQuickUnstable(a, i+1);
	SortQuickUnstable(a+i+1, size-i-1);
}

int main()
{
	int *s=NULL, N;
	cin>>N;
	s = new int[N];
	int j=0;
	while( cin>>s[j++] && j<N );
	cout<<endl<<"Your vector is ";
	PrintVector(s,N);
	cout<<endl;
	
	//cout<<"stat_k = "<<GetStat(s,N,N-1);
	
	SortQuickUnstable(s,N);
	cout<<"Result is ";
	PrintVector(s,N);
	
	delete [] s;
	return 0;
}
