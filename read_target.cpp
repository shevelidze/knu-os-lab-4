#include <unistd.h>
#include <iostream>

int main() {
  int value;

  std::cout << "Process PID: " << getpid() << "\n";
  std::cout << "Variable address: " << &value << "\n";

  while (true) {
    std::cout << "Enter a number ~> ";
    if (!(std::cin >> value)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }

  return 0;
}