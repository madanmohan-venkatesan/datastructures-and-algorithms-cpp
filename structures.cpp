#include <iostream>
using namespace std;
struct rectangle
{
    int lenght;
    int breadth;
};
int main()
{
    rectangle a;
    rectangle *p;
    p=(rectangle *)malloc(sizeof(rectangle));
    p->lenght=55;
    p->breadth=50;
    a.lenght=10;
    a.breadth=20;
    cout << "Size using Pointers\n"<< p->lenght << endl << p->breadth << endl;
    cout << "Size using parameters\n"<< a.lenght << endl << a.breadth << endl;
    return 0;   
}