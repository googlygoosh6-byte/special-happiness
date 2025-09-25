#include <iostream>
using namespace std;

void _if();

int main()
{
    system("clear");
    int mode;
    int value;
    cout << "1. If Conditional\n";
    cout << "\n";
    cout << "------------------------------------------\n\n";
    cout << "Select Mode: ";
    cin >> mode;
    
    switch (mode)
    {
        case 1:
            system("clear");
            _if();
            system("sleep 1");
            break;

        default:
            return -1;
    }
}

void _if()
{
    string pin;
    cout << "Enter the PIN: ";
    cin >> pin;

    if(pin == "123")
    {
        cout << "Logged in.\n";
    }
    else
    {
        cout << "Logging Failed.\n";
    }
}