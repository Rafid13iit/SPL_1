#include <header.h>

void display()
{
    cout << "Hello everyone, Welcome to the sum mania!\n";
    cout << "You give any two number and I add them in a second!\n";

    int a, b;

    cin >> a >> b;

    cout << "The sum is : " << sum(a, b) << endl;

    show();

}

int sum (int a, int b)
{
    return a + b;
}

void show ()
{
    cout << "The program ended here! Thank You...\n";
}