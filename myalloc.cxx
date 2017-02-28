#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

template <class T>
class MyAllocator
{
public:
	string default_filename = "memory.txt";
	string al_filename = "al_memory.txt";
	fstream memory_file;
	fstream al_memory;
	//typedefs
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	
	template <class U>
	struct rebind
	{
		typedef MyAllocator<U> other;
	};
	template <class U>
	MyAllocator (const MyAllocator<U>&)
	{}
	
	MyAllocator ()
	{}
	MyAllocator (const MyAllocator&)
	{}
	~MyAllocator ()
	{
		this->al_memory.open(al_filename, fstream::in);
		this->memory_file.open(default_filename, fstream::app);
		while(this->al_memory.good())
		{
			string str1, str2;
			int ptr, num;
			this->al_memory >> str1 >> str2;
			if (str1 != "" && str2 != "")
			{
				ptr = stoi(str1);
				num = stoi(str2);
				this->memory_file.write(reinterpret_cast<const char *>(ptr), num);
			}
		}
		this->memory_file.close();
		this->al_memory.close();
		remove(al_filename.c_str());
	}
	
	pointer address (reference x) const
	{
		return &x;
	}
	const_pointer address (const_reference x) const
	{
		return &x;
	}
	size_type max_size() const
	{
		return numeric_limits<size_t>::max() / sizeof(value_type);
	}
	pointer allocate (size_type n, const_pointer = 0)
	{
		pointer p = (pointer)(::operator new (n * sizeof(T)));
		//do smth
		this->al_memory.open(al_filename, fstream::app);
		this->al_memory << (int)p << " " << n << endl;
		this->al_memory.close();
		return p;
	}
	void deallocate (pointer p, size_type n)
	{
		::operator delete ((void*)p);
	}
	void construct (pointer p, const value_type &x)
	{
		new (p) value_type(x);
	}
	void destroy (pointer p)
	{
		p->~value_type();
	}
};

template <class T>
inline bool operator == (const MyAllocator<T>&, const MyAllocator<T>&)
{
	return true;
}
template <class T>
inline bool operator != (const MyAllocator<T>&, const MyAllocator<T>&)
{
	return false;
}

int main()
{
	
	vector<char, MyAllocator<char>> DVector(5);
	DVector[0] = 'a';
	DVector[1] = 'b';
	DVector[2] = 'c';
	DVector[3] = 'd';
	DVector[4] = 'e';
	
	return 0;
}
