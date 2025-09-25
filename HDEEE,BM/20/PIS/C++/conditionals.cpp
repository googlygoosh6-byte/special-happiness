// Precompiler code
#include <iostream>
using namespace std; // Standard namespace includes all the standard libraries such as stdio.h 

void _if();
void _login();

int main()
{
    system("clear");
    int mode;
    int value;
    cout << "1. If Conditional\n";
    cout << "2. Login\n";
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
        case 2:
            system("clear");
            _login();
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

void _login()
{
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    
    if(username == "admin" && password == "1234")
    {
        cout << "Login Successful!\n";
    }
    else
    {
        cout << "Logging Failed. Incorrect username or password.\n";
    }
}