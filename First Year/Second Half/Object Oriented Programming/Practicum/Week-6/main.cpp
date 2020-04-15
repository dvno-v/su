
#include "String.cpp"

int main() {
    String a, b("Ivan"), c(b), d("Gosho");
    a.append("Svlachishte shte dostigne ").append(b).append(" i ").append(d).append(" shte bqga");
    a.append("........aaaaaaaaa");
    std::cout << a;
    std::cout << a.empty() << ' ' << a.get_capacity() << ' ' << a.get_length() << '\n';
    a.erase();
    std::cout << a;
    return 0;
}
