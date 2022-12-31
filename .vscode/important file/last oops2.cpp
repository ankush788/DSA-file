#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        int data;

        void get_a(int data){
            this->data = data;
        }
        void display_a(){
            cout << "A - " << this->data << endl;
        }
};

class B: public A{
    public:
        int data;

        void get_b(int data){
            this->data = data;
        }
        void display_b(){
            cout << "B - "<< this->data << endl;
        }
};

class C: public B{
    public:
        int data;

        void get_c(int data){
            this->data = data;
        }

        void display_c(A &a1, B &b1){
            a1.display_a();
            b1.display_b();
            cout << "C - "<< this->data << endl;
        }
};

int main(){
    A a1;
    a1.get_a(5);
    B b1;
    b1.get_b(10);
    C c1;
    c1.get_c(15);
    c1.display_c(a1, b1);
    

    return 0;
}
