#include <iostream>
using namespace std;
class rectangle{
    private:
        int lenght=0;
        int breadth=0;
    public:
        rectangle(int l,int b){
            lenght=l;
            breadth=b;
        }
        int area(){
            return lenght*breadth;
        }
        void assign_breadth(int new_breadth){
            breadth=new_breadth;
        }
        void assign_lenght(int new_lenght){
            lenght=new_lenght;
        }
        void print_properties(){
            cout << "Lenght of rectangle is : " << lenght << endl;
            cout << "Breadth of rectangle is : " << breadth <<endl;
        }
};

int main(){
    rectangle a(10,20);
    a.print_properties();
    a.assign_breadth(35);
    a.print_properties();
    a.assign_lenght(5);
    a.print_properties();
    int area=a.area();
    cout << "The area of the rectangle is " << area << endl;
    return 0;
}