#include <iostream>
using namespace std;
struct rectangle
{
    int lenght=0;
    int breadth=0;
};

int area(rectangle *p){
    int lenght=p->lenght;
    int breadth=p->breadth;
    int area=lenght*breadth;
    return area;
}

void assgin_lenght(rectangle *p,int new_length){
    p->lenght=new_length;
}

void assgin_breadth(rectangle *p,int new_breadth){
    p->breadth=new_breadth;
}

void print_properties(rectangle *p){
    cout << "Lenght of rectangle is : " << p->lenght << endl;
    cout << "Breadth of rectangle is : " << p->breadth <<endl;
}


int main()
{
    rectangle a;
    print_properties(&a);
    assgin_lenght(&a,10);
    print_properties(&a);
    assgin_breadth(&a,20);
    print_properties(&a);
    return 0;   
}