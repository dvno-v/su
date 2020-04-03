
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
    a.print();
    a.index_swap(1,3);
    a.print();
    a.insert(2, 3.1);
    a.print();
    std::cout << a.pop() << "  " << a.pop() << " " << a.unshift() << "  " << a.unshift() << "\n";
    a.print();
    Vector<double> b(a), c = b;
    b.print();
    c.print();
    return 0;
}
