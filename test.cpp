#include <iostream>
using namespace std;

class Father{
    public:
        void print(){
            cout << "Father\n";
        }
};
class Child : public Father{
    public:
        void print(){
            cout << "Child\n";
        }
};


int main(void){
    Child test ;
    test.Father::print();
    return 0;
}