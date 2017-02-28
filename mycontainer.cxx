#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstddef>
//#include <xutility>

template <class T> class List
{
private:
	struct Node
	{
	public:
		T data;
		Node *next, *prev;
		Node ()
		{
			next = nullptr;
			prev = nullptr;
		}
		Node (T data, Node *next = nullptr, Node *prev = nullptr)
			: data(data)
			, next(next)
			, prev(prev)
		{}
	};
	class List_Iterator
	{
	private:
		Node *current;
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef List_Iterator iterator;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		List_Iterator (Node *source): current (source)
		{}
		List_Iterator (): current (nullptr)
		{}
		List_Iterator (iterator *source): current (source->current) // okay?
		{}
		iterator& operator ++ ()
		{
			current = current->next;
			return *this;
		}
		iterator& operator ++ (int)
		{
			return this->operator++();
		}
		iterator& operator -- ()
		{
			current = current->prev;
			return *this;
		}
		iterator& operator -- (int)
		{
			return this->operator--();
		}
		T& operator * ()
		{
			return current->data;
		}
		iterator& operator = (const iterator &iter)
		{
			current = iter.current;
			return *this;
		}
		bool operator == (const iterator &iter)
		{
			return current == iter.current;
		}
		bool operator != (const iterator &iter)
		{
			return current != iter.current;
		}
	};

	Node *head, *tail;	// always head->prev = nullptr; tail->next = nullptr;
						// tail and head don't contain data
public:
	//default constructor
	List ()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	List (const List<T> & list) // copy constructor
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		Node *tmp = list.head->next;
		while (tmp != list.tail)
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
	}
	List (List<T> && list) // move constructor
	{
		head = list.head;
		tail = list.tail;
		list.head = nullptr;
	}
	~List ()
	{
		Node *tmp;
		while (head)
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}
		tail = head; // no elements at all
	}
	int size () const
	{
		int count = 0;
		Node *tmp = head->next;
		while (tmp != tail)
		{
			count++;
			tmp = tmp->next;
		}
		return count;
	}
	bool empty () const
	{
		return head->next != tail;
	}
	T& front () const
	{
		assert(head->next != nullptr);
		return head->next->data;
	}
	T& back () const
	{
		assert(tail->prev != nullptr);
		return tail->prev->data;
	}
	void push_front (const T &data)
	{
		Node *after_head = new Node (data, head->next, head);
		head->next->prev = after_head;
		head->next = after_head;
	}
	void push_back (const T &data)
	{
		Node *before_tail = new Node (data, tail, tail->prev);
		tail->prev->next = before_tail;
		tail->prev = before_tail;
	}
	void pop_front ()
	{
		assert (!empty());
		Node *tmp = head->next;
		head->next = head->next->next;
		head->next->prev = head;
		delete tmp;
	}
	void pop_back ()
	{
		assert (!empty());
		Node *tmp = tail->prev;
		tail->prev = tail->prev->prev;
		tail->prev->next = tail;
		delete tmp;
	}
	void insert_before (int pos, const T &data)
	{
		assert (pos < size());
		Node *tmp = head->next;
		for (int i=0; i<pos; i++)
			tmp = tmp->next;
		Node *new_ = new Node(data, tmp, tmp->prev);
		tmp->prev->next = new_;
		tmp->prev = new_;
	}
	void insert_after (int pos, const T &data)
	{
		assert (pos < size());
		Node *tmp = head;
		for (int i=0; i<pos; i++)
			tmp = tmp->next;
		Node *new_ = new Node(data, tmp->next, tmp);
		tmp->next->prev = new_;
		tmp->next = new_;
	}
	void erase (int pos)
	{
		assert (pos < size());
		Node *tmp = head;
		for (int i=0; i<pos; i++)
			tmp = tmp->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
	}
	List<T>& operator = (const List<T> & list) //copy
	{
		while (!empty())
			pop_front();
		Node *tmp = list.head->next;
		while (tmp != tail)
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}
	List<T>& operator = (List<T> && list) // move
	{
		while (!empty())
			pop_front();
		head = list.head;
		tail = list.tail;
		list.head = nullptr;
		return *this;
	}
	void display()
	{
		Node *tmp = head->next;
		while (tmp != tail)
		{
			std::cout << tmp->data << std::endl;
			tmp = tmp->next;
		}
	}
	// iterators
	typedef List_Iterator iterator;
	typedef ptrdiff_t difference_type;
	List_Iterator begin() const
	{
		return List_Iterator (head->next);
	}
	List_Iterator end() const
	{
		return List_Iterator (tail);
	}
};

int main()
{
	List<int> mylist;
	mylist.push_back(10);
	mylist.push_back(5);
	mylist.push_back(1);
	List<int>::iterator it1 = mylist.begin();
	std::advance(it1,1);
	//std::cout << std::distance(it1, it2) << std::endl;
	//for (; it1 != mylist.end(); ++it1)
		//std::cout << *it1 << " ";
	return 0;
}
