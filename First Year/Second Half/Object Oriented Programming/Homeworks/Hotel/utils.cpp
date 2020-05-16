#ifndef UTILS_CPP
#define UTILS_CPP

#include <vector>
#include <string>

void get_tokens(std::vector<std::string>& v, const std::string& input){
  v.erase(v.cbegin(), v.cend());
  std::string temp = "";
  for (size_t i = 0; i < input.length(); i++) {
    if(input.at(i) != ' '){
      temp += input.at(i);
    }else{
      v.push_back(temp);
      temp = "";
    }
  }
  v.push_back(temp);
}

#endif /* end of include guard: UTILS_CPP */
