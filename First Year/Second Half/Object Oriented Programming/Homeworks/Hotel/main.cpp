#include <iostream>
#include <fstream>
#include "Date.cpp"
#include "Room.cpp"

//important
//file << "...."  write in file
//file >> "...."  read from file


int main(){
	//test dates
	/* Date d(2012, 2, 29), a = d, b(2013, 3, 29);*/

	//test files
/*	char asd[] = "asd";
	std::cout << "ASD\n";
	Room r;
	std::cout << "ASD\n";
	std::fstream file;
	file.open("chushka.pesho", std::ios::out);
	if(!file){
		std::cout << "ASD\n";
	}

	file >> r;
	std::cout << "ASD\n";
	file >> r;
	std::cout << "ASD\n";
	file << asd;
	std::cout << "ASD\n";
*/

	//test tokens
	/*std::vector<std::string> strs;
	std::string one_str = "Iskam da qm chushki i da sym mega fenci bog";
	get_tokens(strs, one_str);
	for (size_t i = 0; i < strs.size(); i++) {
		std::cout << strs[i] << "\n";
	}*/

	return 0;
}
