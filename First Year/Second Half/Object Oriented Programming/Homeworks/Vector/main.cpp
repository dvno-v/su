
#include "Vector.hpp"


int main() {
    Vector<double> a;
    a.push(1.2);
    std::cout << "Push\n";
    a.print();
    std::cout << "Push\n";
    a.push(1.3);
    a.print();
    std::cout << "Push\n";
    a.push(1.4);
    a.print();
    std::cout << "Push\n";
    a.push(1.5);
    a.print();
    std::cout << "Push\n";
    a.push(1.6);
    a.print();
    std::cout << "Push\n";
    a.push(1.7);
    a.print();
    std::cout << "Push\n";
    a.push(1.8);
    a.print();
    std::cout << "Swap\n";
    a.index_swap(1,3);
    a.print();
    std::cout << "Insert\n";
    a.insert(2, 3.1);
    a.print();
    std::cout << a.pop() << "  " << a.pop() << " " << a.shift() << "  " << a.shift() << "\n";
    a.print();
    double arr[] = {2.1, 3, 3, 4.1};
    Vector<double> b(a), c = b, d(arr, 4);
    b.print();
    c.print();
    d.print();
    return 0;
}
