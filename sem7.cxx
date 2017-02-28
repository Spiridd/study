#include <iostream>
#include <string>
using namespace std;
struct bhnode
{
	string data;
	int priority;
	void display()
	{
		cout<<data<<", "<<priority<<endl;
	}
};

class priorityQueue
{
	bhnode *body;
	int numnodes;
	int bodysize;
	void heapify()
	{
	}
	void swap(int child, int parent)
	{
		bhnode x=body[child];
		body[child]=body[parent];
		body[parent]=x;
	}
public:
	priorityQueue(int max)
	{
		body=new bhnode[max+1]; //index =1,2,3,..,max (we don't use the zero index)2222222
		numnodes=0;
		bodysize=max;
	}
	~priorityQueue()
	{
		delete [] body;
	}
	int insert(bhnode elem)
	{
		if( numnodes>=bodysize )
			return -1;
		body[++numnodes]=elem;
		for(int i=numnodes; i>1 && body[i].priority<body[i/2].priority; i=i/2)
		{
			swap(i,i/2);
		}
		return 0;
	}
	void display()
	{
		for(int i=1;i<=bodysize;i++)
			body->display();
	}
	//void remove(int x)
};

int main()
{
	priorityQueue queue(1);
	return 0;
}
