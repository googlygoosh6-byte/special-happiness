#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	string pass;
	cout << "Start Counting (y/n)\n";
	cin >> pass;
	
	while (pass == "y" || pass == "Y")
	{
		cout << "x = " << x << endl;
		x++;
	}
	
	cout << "System END\n";
}
