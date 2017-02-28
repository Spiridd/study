#include <iostream>
#include <thread>
#include <string>

using namespace std;

void printer ()
{
	for (int i=0; i<100; i++)
		cout << "printer: " << i << endl;
}

int main ()
{
	thread t1 (printer);
	for (int j=0; j>-100; j--)
		cout << "main: " << j << endl;
	t1.join();
	return 0;
}
