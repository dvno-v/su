
#include "Vector.cpp"


int main() {
    Vector<double> a;
    a.push(1.2);
    a.push(1.3);
    a.push(1.4);
    a.push(1.5);
    a.push(1.6);
    a.push(1.7);
    a.push(1.8);
    a.index_swap(1,3);
    a.print();
    a.insert(2, 3.1);
    a.print();
    return 0;
}
