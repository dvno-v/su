#include <iostream>

#include "User.cpp"


int main(){
    char a[MAX_NAME_LENGTH], b[MAX_NAME_LENGTH];
    int c;
    std::cin.getline(a, MAX_NAME_LENGTH, ' ');
    std::cin >> c; 
    std::cin.get();
    std::cin.getline(b, MAX_EMAIL_LENGTH);
    User u(a,c,b);
    u.print();

    return 0;
}