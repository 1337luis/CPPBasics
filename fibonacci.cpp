#include <iostream>

using namespace std;

int main()
{
	int total = 50;			//TOTAL FIBONACCI NUMBERS, CHANGE IT TO MORE OR LESS

	//LONG LONG gives a max of 2^64
	unsigned long long x = 0;	//LVAL1
	unsigned long long y = 0;	//LVAL2
	unsigned long long a = 1;	//Actual value

	

	for (  int z = 0; z < total; z++ )
	{
		cout << a << endl;	//SHOWS ACTUAL NUMBER (a)
		x = y;			//SHIFTS X to Y Value
		y = a;			//SHIFTS Y to Actual value
		a = x + y;		//Actual is  x + y
	}

	system( "PAUSE" );		//DONT CLOSE CONSOLE AT THE END (WINDOWS)
	return 0;
}
