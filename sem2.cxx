#include <iostream>
#include <string>
using namespace std;
//s - string
//p0,01,...,pk-1
//|A|=3 (power)
//can they cover string?
struct tree
{
	tree c[3];
	bool end;
	//constructor
	tree()
	{
		c[0]=c[1]=c[2]=NULL;
		end=false;
	}
};
bool insert(tree *root, string s)
{
	for(auto c:s)
	{
		if( root->c[c-'a']==NULL )
			root->c[c-'a']=new tree;
		root=root->c[c-'a'];
		if( root->end )
			return false;
	}
	return root->end=true;
}
bool cover(tree *root, string s)
{
	tree *r=root;
	for(auto c:s)
	{
		r=r->c[c-'a'];
		if( r==NULL )
			return false;
		if( r->end )
			r=root;
	}
	return r==root;
}
int main()
{
	tree->root=new tree;
	//for...p...
	//insert(root,p);
	return 0;
}

