#include <iostream>
#include "Person.cpp"

int main() {
	char name[] = "Gosho";
	Person gosho(name, true, 18, true);
	gosho.print_person();
	return 0;
}