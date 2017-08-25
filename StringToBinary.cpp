#include <iostream>
#include <string>
#include <sstream>

std::string translateCharIntoBinary(char c) {
  int i = static_cast<int>(c);
  std::stringstream ss;
  int digit1 = static_cast<bool>(i & 128);
  int digit2 = static_cast<bool>(i & 64);
  int digit3 = static_cast<bool>(i & 32);
  int digit4 = static_cast<bool>(i & 16);
  int digit5 = static_cast<bool>(i & 8);
  int digit6 = static_cast<bool>(i & 4);
  int digit7 = static_cast<bool>(i & 2);
  int digit8 = static_cast<bool>(i & 1);
  ss << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8;
  return ss.str();
}

int main() {
  std::cout << "Write your string to be converted into binary.\n";
  std::string input;
  std::getline(std::cin, input);
  for (auto i = input.begin(); i != input.end(); ++i) {
    char thisChar = *i;
    std::cout << translateCharIntoBinary(thisChar) << " ";
  }
}
