#include <iostream>
#include <string>
using namespace std;

int main()
{
	int p = 57229;
	cout << "hey" << endl;
	string s =  to_string(p);
	const char *x = s.c_str();
	cout << x;
	return 0;
}
