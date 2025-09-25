#include <iostream>
using namespace std;

void _while();
void _dowhile(int limit);
void _for(int limit);

int main(int argc, char **argv)
{
	if(argc < 2 && argc > 3)
	{
		cout << "Usage: ./repitition [mode] [value]\n";
		return -1;
	}

	system("clear");

	switch (*argv[1])
	{
		case '1':
			_while();
			system("sleep 1");
			break;
		case '2':
			_dowhile(*argv[2]-48);
			system("sleep 1");
			break;
		case '3':
			_for(*argv[2]-48);
			system("sleep 1");
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