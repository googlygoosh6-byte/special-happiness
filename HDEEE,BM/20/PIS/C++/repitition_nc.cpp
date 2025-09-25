#include <iostream>
using namespace std;

void _while();
void _dowhile(int limit);
void _for(int limit);

int main()
{
	system("clear");
    int mode;
    int value;
    cout << "1. While Loop\n";
    cout << "2. Do While Loop\n";
    cout << "3. For Loop\n";
    cout << "Select Mode: ";
    cin >> mode;
    
    switch (mode)
    {
        case 1:
            system("clear");
            _while();
            system("sleep 1");
            break;
        case 2:
            system("clear");
            cout << "Please Enter Value";
            cin >> value;
            _dowhile(value);
            system("sleep 1");
            break;
        case 3:
            cout << "Please Enter Value";
            cin >> value;
            _for(value);
            system("sleep 1");
            break;
    
        default:
            return -1;
    }
}

void _while()
{
	int x = 0;
	string pass;
	cout << "Start Counting (y/n): ";
	cin >> pass;
	
	while (pass == "y" || pass == "Y")
	{
		cout << "x = " << x << endl;
		x++;
	}
	
	cout << "System END\n";
}

void _dowhile(int limit)
{
	int i = 1;
	do
	{
		cout << "Round " << i << endl;
		i++;
	}
	while(i <= limit);
}

void _for(int limit)
{
	for (int i = 1; i <= limit; i++)
	{
		cout << i << " Round\n";
	}
}