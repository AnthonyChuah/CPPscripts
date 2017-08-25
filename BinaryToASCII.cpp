#include <iostream>
#include <cstdlib>
#include <string>

int main() {
  while (true) {
    std::cout << "Write your binary numbers and I will tell you the (decimal) value and ASCII value:\n";
    std::string input;
    std::cin >> input;
    for (auto i = input.begin(); i != input.end(); ++i) {
      char thisChar = *i;
      if (!(thisChar == '0' || thisChar == '1')) {
	std::cout << "Your input must only contain 1s or 0s.\n";
	exit(1);
      }
    }
    int thisValue = std::stoi(input, nullptr, 2);
    std::cout << "The corresponding decimal value is: " << thisValue << "\n";
    char thisAscii = static_cast<char>(thisValue);
    std::cout << "The corresponding ASCII char is: " << thisAscii << "\n";
  }
}
