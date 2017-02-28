#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <string>
#include <cstdio>
using namespace std;
template <class T>
class MyAlloc
{
public:
	string alloc_name;
	fstream alloc_file;

	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;

	template <class U>
	struct rebind
	{
		typedef MyAlloc<U> other;
	};

	MyAlloc ()
	{
        alloc_name = "alloc.txt";
    }

	MyAlloc (const MyAlloc&)
	{
        alloc_name = "alloc.txt";
    }

	template <class U>
	MyAlloc (const MyAlloc<U>&)
	{
        alloc_name = "alloc.txt";
    }

	~MyAlloc ()
	{}

	pointer address(reference x) const
	{
		return &x;
	}

	const_pointer address(const_reference x) const
	{
		return &x;
	}

	pointer allocate (size_type n, const_pointer = 0)
	{
		return (pointer)(::operator new(n * sizeof(value_type)));
	}

	void deallocate (pointer p, size_type num)
	{
	    cout << "deallocate" << endl;
	    alloc_file.open (alloc_name, fstream::app);
	    for (size_type i=0; i<num; i++)
			alloc_file << *(p+i) << " ";
		alloc_file << endl;
 		alloc_file.close();
		::operator delete((void*)p);
	}

	size_type max_size() const
	{
		return numeric_limits<size_t>::max() / sizeof(value_type);
	}

	void construct(pointer p, const value_type& x)
	{
		new((void*)p) value_type(x);
	}

	void destroy(pointer p)
	{
		p->~T();
	}
};

template <class U>
inline bool operator == (const MyAlloc<U>&, const MyAlloc<U>&)
{
	return true;
}

template <class U>
inline bool operator != (const MyAlloc<U>&, const MyAlloc<U>&)
{
	return false;
}


int main()
{
	vector<char, MyAlloc<char>> DVector(5);
	DVector[0] = 'a';
	DVector[1] = 'b';
	DVector[2] = 'c';
	DVector[3] = 'd';
	DVector[4] = 'e';

	vector<int, MyAlloc<int>> DuVector(5);
	DuVector[0] = 10;
	DuVector[1] = -2;
	DuVector[2] = 3;
	DuVector[3] = 17;
	DuVector[4] = 21;

	vector<double, MyAlloc<double>> NewVector(3);
	NewVector[0] = 3.5;
	NewVector[1] = -7.345;
	NewVector[2] = 100;

	return 0;
}
